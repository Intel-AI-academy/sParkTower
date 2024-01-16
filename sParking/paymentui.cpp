#include "paymentui.h"
#include "ui_paymentui.h"

PaymentUI::PaymentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentUI)
{
    ui->setupUi(this);
    p_paymentdialog = new PaymentDialog;

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(push_back_button()));
    connect(ui->payment_button, SIGNAL(clicked()), this, SLOT(show_pay_dialog_view()));
}

void PaymentUI::push_back_button()
{
    emit push_back();

}

void PaymentUI::show_pay_dialog_view()
{
    p_paymentdialog->show();
}

PaymentUI::~PaymentUI()
{
    delete ui;
}
