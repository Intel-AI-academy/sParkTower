#include "usermodeui.h"
#include "ui_usermodeui.h"

UserModeUI::UserModeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserModeUI)
{
    ui->setupUi(this);

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(push_back_button()));
    connect(ui->number0, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number1, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number2, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number3, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number4, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number5, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number6, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number7, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number8, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->number9, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->cancel_button, SIGNAL(clicked()), this, SLOT(input_key()));
    connect(ui->check_button, SIGNAL(clicked()), this, SLOT(input_key()));

    output_text = "";
    check_num = 0;
}

void UserModeUI::push_back_button()
{
    emit push_back();
    output_text = "";
    ui->carnum_text->setText(output_text);
    ui->phonenum_text->setText(output_text);
    check_num = 0;
}

void UserModeUI::input_key()
{

    QPushButton *button = (QPushButton *)sender();
    QString input_text = button->text();
    QString carnum_temp;
    QString phonenum_temp;
/*
    if(input_text == "Cancel")
    {
        output_text = "";
        ui->carnum_text->setText(output_text);
        ui->phonenum_text->setText(output_text);
        check_num = 0;
    }
    else if(input_text == "Check")
    {
        check_num++;
        output_text = "";
    }
    else
    {
        output_text += input_text;
    }

    if(check_num == 0)
    {
        ui->carnum_text->setText(output_text);
    }
    else if(check_num == 1)
    {
        ui->phonenum_text->setText(output_text);
    }
    else
    {
        // register popup or error msg
    }
*/
    if(input_text == "Check")
    {


        carnum_temp = ui->carnum_text->text();
        phonenum_temp = ui->phonenum_text->text();

        //p_InfoDatabase->user_data(carnum_temp);
        //p_InfoDatabase->user_data(phonenum_temp);

        if(carnum_temp == "1" && phonenum_temp == "1")
        {
            // open payment
            input_time = QDateTime::currentDateTime();
            QString temp_time = input_time.toString();
            emit move_to_payment();
            emit in_time(temp_time);
        }
        else
        {
            // open registration
            emit move_to_registrationcar();
        }
    }

}

UserModeUI::~UserModeUI()
{
    delete ui;
}
