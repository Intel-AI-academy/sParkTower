#include "paymentdialog.h"
#include "ui_paymentdialog.h"

PaymentDialog::PaymentDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentDialog)
{
    ui->setupUi(this);
    connect(ui->cancel_button, SIGNAL(clicked()), this, SLOT(close_dialog()));
    connect(ui->check_button, SIGNAL(clicked()), this, SLOT(show_payment_msg()));
}

void PaymentDialog::close_dialog()
{
    close();
}

void PaymentDialog::show_payment_msg()
{
    emit pay();
    payment_msg.setText("Payment Success");
    payment_msg.exec();
}

PaymentDialog::~PaymentDialog()
{
    delete ui;
}
