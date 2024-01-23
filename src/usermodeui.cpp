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
    if(input_text == "Check" && check_num == 2)
    {
        compare();
        check_num = 0;
    }
}

void UserModeUI::compare()
{
    QString carnum_temp = ui->carnum_text->text();
    QString phonenum_temp = ui->phonenum_text->text();

    int row_count = 0;
    int register_count = 0;
    QString recv_data = "";
    QString str_query = "SELECT * FROM parking_log_tb WHERE charge_check = 'x'";
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
            QStringList qlist = recv_data.split('@');
            if(qlist[1] == carnum_temp && qlist[2] == phonenum_temp)
            {
                QString time_format = "HH:mm:ss";
                temp_time = QDateTime::currentDateTime();
                QString output_time = temp_time.toString(time_format);

                row_count++;
                emit move_to_payment(qlist[1], qlist[2]);
            }
            recv_data = "";
        }
        if(!row_count)
        {
            for(i=0;i<2;i++)
            {
                if(charging_slot[i]==1)
                {
                    register_count++;
                }
            }
            if(register_count < 2)
                emit move_to_registrationcar();
            else
            {
                cannot_parking_msg.setText("Not enough parking slot!!");
                cannot_parking_msg.exec();
            }
        }
    }
}

void UserModeUI::register_car()
{
    QString time_format = "HH:mm:ss";
    temp_time = QDateTime::currentDateTime();
    QString input_time = temp_time.toString(time_format);
    for(i=0;i<2;i++)
    {
        if(charging_slot[i] == 0)
        {
            send_data = QString::number(i+1);
            send_data += '@';
            charging_slot[i] = 1;

            send_data += ui->carnum_text->text();
            send_data += '@';
            send_data += ui->phonenum_text->text();
            send_data += '@';
            send_data += input_time;
            send_data += '@';
            send_data += "null";
            send_data += '@';
            send_data += 'x';
            emit send_data_to_db(send_data);
            send_data_slot(QString::number(i+1));
            break;
        }
    }
    push_back_button();
}

void UserModeUI::send_data_slot(QString send_data)
{
    QString str_recv_id = "tower";
    QString str_send_data = send_data;

    if(!str_send_data.isEmpty())
    {
        str_send_data = "["+str_recv_id+"]" + "Park@" + str_send_data;
    }
    emit socket_send_data(str_send_data);
}

void UserModeUI::update_charging_slot(int check_num)
{
    charging_slot[check_num-1]=0;
}

QPushButton* UserModeUI::get_main_ui_button()
{
    return ui->check_button;
}


UserModeUI::~UserModeUI()
{
    delete ui;
}
