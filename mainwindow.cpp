//
// Created by mikesolar on 25-6-1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    titleEdit=new QLineEdit(this);
    dateEdit=new QLineEdit(this);
    editorsEdit=new QLineEdit(this);
    isFirstPageCheckBox=new QCheckBox(this);
    addArticleButton=new QPushButton(this);
    saveButton=new QPushButton(this);
    exportButton=new QPushButton(this);
    editHeadNewsButton=new QPushButton(this);
    headDialog=new HeadDialog(this);
    headDialog->close();
    // 布局
    this->setLayout(&mainLayout);

    // 是不是第一版
    headLayout.addWidget(isFirstPageCheckBox);
    headLayout.addWidget(editHeadNewsButton);
    mainLayout.addLayout(&headLayout);

    // 是不是第一版都要有
    mainLayout.addWidget(titleEdit);
    mainLayout.addWidget(dateEdit);
    mainLayout.addWidget(editorsEdit);

    // 按钮
    articleButtonLayout.addWidget(addArticleButton);
    articleButtonLayout.addWidget(saveButton);
    articleButtonLayout.addWidget(exportButton);
    mainLayout.addLayout(&articleButtonLayout);

    editHeadNewsButton->setDisabled(true);

    // 初始化信号和槽
    connect(isFirstPageCheckBox, &QCheckBox::stateChanged, this, &MainWindow::isFirstPageChecked);
    connect(editHeadNewsButton, &QPushButton::clicked, this, &MainWindow::editHeadNewsButtonClicked);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::isFirstPageChecked(int checked) {
    if (checked) {
        editHeadNewsButton->setDisabled(false);
    }
    else {
        editHeadNewsButton->setDisabled(true);
    }
}

void MainWindow::editHeadNewsButtonClicked() {
    headDialog->show();
    headDialog->open();
}
