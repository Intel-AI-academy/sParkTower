#include "checkpayment.h"
#include "ui_checkpayment.h"

CheckPayMent::CheckPayMent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckPayMent)
{
    ui->setupUi(this);
}

CheckPayMent::~CheckPayMent()
{
    delete ui;
}
