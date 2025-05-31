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
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ArticleInput: public QObject {
private:
    Q_OBJECT
    QLineEdit *title;
    QLineEdit *from;
    QTextEdit *content;
    QPushButton *addPictureButton;
    QList<QPushButton> *deletePictureButtons;
    QPushButton *deleteArticleButton;
public:
    ArticleInput(QWidget* parent=nullptr) {
        title=new QLineEdit(parent);
        from=new QLineEdit(parent);
        content=new QTextEdit(parent);
        addPictureButton=new QPushButton(parent);
        deleteArticleButton=new QPushButton(parent);
        deletePictureButtons=new QList<QPushButton>;
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
    QLineEdit *titleEdit;
    QLineEdit *dateEdit;
    QLineEdit *editorsEdit;
    QCheckBox *isFirstPageCheckBox;
    QPushButton *addArticleButton;
    QPushButton *saveButton;
    QPushButton* exportButton;
    QPushButton *editHeadNewsButton;
    QList<ArticleInput> articleInputs;
    QVBoxLayout mainLayout;
    QHBoxLayout articleButtonLayout;
    QHBoxLayout headLayout;

    HeadDialog *headDialog;

};


#endif //MAINWINDOW_H
