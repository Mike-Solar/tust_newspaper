//
// Created by mikesolar on 25-6-1.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QList>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCheckBox>
#include "Article.h"
#include "HeadDialog.h"
#include <QGridLayout>
#include <QLabel>
QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class ArticleInput : public QObject {
private:
    Q_OBJECT
    QLabel *titleLabel;
    QLineEdit *title;
    QLabel *fromLabel;
    QLineEdit *from;
    QLabel *contentLabel;
    QTextEdit *content;
    QPushButton *addPictureButton;
    QList<QLabel > *pictureLabels;
    QList<QPushButton> *deletePictureButtons;
    QPushButton *deleteArticleButton;
    QGridLayout *mainLayout;
    QGridLayout *pictureLayout;

    QWidget *parent=nullptr;
public:
    ArticleInput(QVBoxLayout &&layout,QWidget *parent = nullptr) {
        this->parent = parent;

        title = new QLineEdit(parent);
        titleLabel = new QLabel(parent);
        from = new QLineEdit(parent);
        fromLabel = new QLabel(parent);
        content = new QTextEdit(parent);
        contentLabel = new QLabel(parent);
        addPictureButton = new QPushButton(parent);
        deleteArticleButton = new QPushButton(parent);
        deletePictureButtons = new QList<QPushButton>;
        mainLayout = new QGridLayout(parent);
        mainLayout->addWidget(titleLabel, 0, 0, 1, 1);
        mainLayout->addWidget(title, 0, 1, 1, 1);
        mainLayout->addWidget(fromLabel, 1, 0, 1, 1);
        mainLayout->addWidget(from, 1, 1, 1, 1);
        mainLayout->addWidget(contentLabel, 2, 0, 1, 2);
        mainLayout->addWidget(content, 3, 0, 5, 2);
        mainLayout->addWidget(addPictureButton, 4, 0, 1, 2);
        pictureLayout = new QGridLayout(parent);
        pictureLayout->setColumnStretch(0, 6);
        pictureLayout->setColumnStretch(1, 1);
        mainLayout->addLayout(pictureLayout, 5, 0, 5, 2);

        layout.addLayout(mainLayout);
    }
public slots:
    void addPicture(QString path) {
        pictureLabels->append(QLabel(path,parent));
        deletePictureButtons->append(QPushButton(parent));
        pictureLayout->addWidget(&pictureLabels->last(), 0, 0, 1, 1);
        pictureLayout->addWidget(&deletePictureButtons->last(), 0, 1, 1, 1);
    }
    ~ArticleInput() {
        delete deletePictureButtons;
    }
};


class MainWindow : public QMainWindow {
    Q_OBJECT
signals:

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:
    void isFirstPageChecked(int checked);

    void editHeadNewsButtonClicked();

    void newArticle();

    void deleteArticle();

    void addPicture();

    void deletePicture();

private:
    Ui::MainWindow *ui;
    // 数据
    std::vector<Article> articles;
    QString title;
    QString date;
    QString editors;
    bool isFirstPage;
    Article head; // 头版
    // 控件
    QLabel *titleLabel;
    QLineEdit *titleEdit;
    QLabel *dateLabel;
    QLineEdit *dateEdit;
    QLabel *editorsLabel;
    QLineEdit *editorsEdit;
    QCheckBox *isFirstPageCheckBox;
    QPushButton *addArticleButton;
    QPushButton *saveButton;
    QPushButton *exportButton;
    QPushButton *editHeadNewsButton;
    QList<ArticleInput> articleInputs;
    QGridLayout mainLayout;
    QVBoxLayout articleListLayout;
    QGridLayout articleLayout;
    QHBoxLayout articleButtonLayout;
    QHBoxLayout headLayout;

    HeadDialog *headDialog;
};


#endif //MAINWINDOW_H
