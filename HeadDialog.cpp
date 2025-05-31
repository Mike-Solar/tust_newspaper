//
// Created by mikesolar on 25-6-1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HeadDialog.h" resolved

#include "HeadDialog.h"
#include "ui_HeadDialog.h"


HeadDialog::HeadDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::HeadDialog) {
    ui->setupUi(this);
}

HeadDialog::~HeadDialog() {
    delete ui;
}
