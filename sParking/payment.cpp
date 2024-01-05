#include "payment.h"
#include "ui_payment.h"

Payment::Payment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Payment)
{
    ui->setupUi(this);
    connect(ui->pPBToMain, SIGNAL(clicked()), this, SLOT(push_to_main()));
}


Payment::~Payment()
{
    delete ui;
}
