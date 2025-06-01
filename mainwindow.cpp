//
// Created by mikesolar on 25-6-1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    titleLabel = new QLabel("本版标题",this);
    titleEdit=new QLineEdit(this);
    dateLabel = new QLabel("日期和版数",this);
    dateEdit=new QLineEdit(this);
    editorsLabel = new QLabel("编辑",this);
    editorsEdit=new QLineEdit(this);
    isFirstPageCheckBox=new QCheckBox(this);
    isFirstPageCheckBox->setText("是否为第一版");
    isFirstPageCheckBox->setChecked(false);
    addArticleButton=new QPushButton("添加文章",this);
    saveButton=new QPushButton("保存",this);
    exportButton=new QPushButton("导出PDF",this);
    editHeadNewsButton=new QPushButton("编辑头条",this);
    headDialog=new HeadDialog(this);
    headDialog->close();
    // 布局
    this->setLayout(&mainLayout);

    // 是不是第一版
    headLayout.addWidget(isFirstPageCheckBox);
    headLayout.addWidget(editHeadNewsButton);
    mainLayout.addLayout(&headLayout, 0, 0, 1, 2);

    // 不管是不是第一版都要有
    mainLayout.addWidget(titleLabel, 1, 0, 1, 1);
    mainLayout.addWidget(titleEdit, 1, 1, 1, 1);
    mainLayout.addWidget(dateLabel, 2, 0, 1, 1);
    mainLayout.addWidget(dateEdit, 2, 1, 1, 1);
    mainLayout.addWidget(editorsLabel, 3, 0, 1, 1);
    mainLayout.addWidget(editorsEdit, 3, 1, 1, 1);

    // 按钮
    articleButtonLayout.addWidget(addArticleButton);
    articleButtonLayout.addWidget(saveButton);
    articleButtonLayout.addWidget(exportButton);
    mainLayout.addLayout(&articleButtonLayout, 4, 0, 1, 2);

    editHeadNewsButton->setDisabled(true);

    // 初始化信号和槽
    connect(isFirstPageCheckBox, &QCheckBox::stateChanged, this, &MainWindow::isFirstPageChecked);
    connect(editHeadNewsButton, &QPushButton::clicked, this, &MainWindow::editHeadNewsButtonClicked);
    connect(addArticleButton, &QPushButton::clicked, this, &MainWindow::newArticle);
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

void MainWindow::newArticle() {
    articleInputs.append(ArticleInput(std::forward<QVBoxLayout>(articleListLayout), this));
}

void MainWindow::deleteArticle() {

}
