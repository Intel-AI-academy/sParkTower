#include "registerdialog.h"
#include "ui_registerdialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);

    connect(ui->cancel_button, SIGNAL(clicked()), this, SLOT(close_dialog()));
    connect(ui->check_button, SIGNAL(clicked()), this, SLOT(show_register_box()));
}

void RegisterDialog::close_dialog()
{
    close();

}

void RegisterDialog::show_register_box()
{
    emit register_car();
    register_msg.setText("Register Success");
    register_msg.exec();
    close();
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}