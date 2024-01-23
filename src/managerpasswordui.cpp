#include "managerpasswordui.h"
#include "ui_managerpasswordui.h"

ManagerPasswordUI::ManagerPasswordUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerPasswordUI)
{
    ui->setupUi(this);
    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(move_back()));
    connect(ui->check_button, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->cancel_button, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number0, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number1, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number2, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number3, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number4, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number5, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number6, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number7, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number8, SIGNAL(clicked()), this, SLOT(move_manager_view()));
    connect(ui->number9, SIGNAL(clicked()), this, SLOT(move_manager_view()));

    button_pasword = "";
}

void ManagerPasswordUI::move_back()
{
    ui->password_line->setText("");
    close();
}

void ManagerPasswordUI::move_manager_view()
{
    QPushButton *button = (QPushButton *)sender();
    QString input_text = button->text();

    if(input_text != "Check")
    {
        button_pasword += input_text;

        ui->password_line->setText(button_pasword);
    }

    if(input_text == "Check"){

        if(button_pasword !="1111")
        {
            password_error_msg.setText("Password Error!");
            password_error_msg.exec();
        }
        else
        {
            close();
            ui->password_line->setText("");
            emit manager_view();
        }
        button_pasword = "";
    }

    else if(input_text == "Cancel")
    {
        button_pasword = "";
        ui->password_line->clear();
    }

}


ManagerPasswordUI::~ManagerPasswordUI()
{
    delete ui;
}
