//
// Created by mikesolar on 25-6-1.
//

#ifndef HEADDIALOG_H
#define HEADDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class HeadDialog; }
QT_END_NAMESPACE

class HeadDialog : public QDialog {
Q_OBJECT

public:
    explicit HeadDialog(QWidget *parent = nullptr);
    ~HeadDialog() override;

private:
    Ui::HeadDialog *ui;
    QLineEdit *titleEdit;
    QLineEdit *fromEdit;
    QTextEdit *contentEdit;
};


#endif //HEADDIALOG_H
