#include "usermodeui.h"
#include "ui_usermodeui.h"

UserModeUI::UserModeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserModeUI)
{
    ui->setupUi(this);

    for(i=0;i<2;i++)
    {
        charging_slot[i] = 0;
        parking_slot[i] = 0;
    }

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
    send_data = "";
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
        compare();
    }
}

void UserModeUI::compare()
{
    QString carnum_temp = ui->carnum_text->text();
    QString phonenum_temp = ui->phonenum_text->text();
    int row_count = 0;
    QString recv_data = "";
    QString str_query = "select * from parking_log_tb where charge_check == 'x'";
    QSqlQuery sql_query;
    if(!sql_query.exec(str_query))
        ;
    else
    {
        while (sql_query.next())
        {
            recv_data = sql_query.value("car_slot_num").toString();
            recv_data += '@';
            recv_data += sql_query.value("car_num").toString();
            recv_data += '@';
            recv_data += sql_query.value("phone_num").toString();
            recv_data += '@';
            recv_data += sql_query.value("input_time").toString();
            recv_data += '@';
            recv_data += sql_query.value("output_time").toString();
            recv_data += '@';
            recv_data += sql_query.value("charge_check").toString();
            QStringList qlist = recv_data.split('@');
            if(qlist[1] == carnum_temp && qlist[2] == phonenum_temp)
            {
                // open payment
                emit move_to_payment();
                row_count++;
            }
            recv_data = "";
        }
        if(!row_count)
        {
            // open registration
            emit move_to_registrationcar();
        }
    }
}

void UserModeUI::register_car()
{
    QString time_format = "yyyy/MM/dd HH:mm:ss";
    temp_time = QDateTime::currentDateTime();
    QString input_time = temp_time.toString(time_format);

    for(i=0;i<2;i++)
    {
        if(charging_slot[i] == 0)
        {
            send_data = QString::number(i+1);
            send_data += '@';
            charging_slot[i] = 1;
            break;
        }
    }
    send_data += ui->carnum_text->text();
    send_data += '@';
    send_data += ui->phonenum_text->text();
    send_data += '@';
    send_data += input_time;
    send_data += '@';
    send_data += "null";
    send_data += '@';
    send_data += 'x';
    qDebug() << send_data;
    emit send_data_to_db(send_data);
}

UserModeUI::~UserModeUI()
{
    delete ui;
}
