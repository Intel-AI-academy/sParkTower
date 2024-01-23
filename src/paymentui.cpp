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
    connect(p_paymentdialog, SIGNAL(pay()), this, SLOT(send_payment_data()));
    car_num = "";
    phone_num = "";
    input_time = "";
    parking_fee_data = "";
    charging_fee_data = "";
}

void PaymentUI::set_fee(QString parking_fee, QString charging_fee)
{
        parking_fee_data = parking_fee;

        charging_fee_data = charging_fee;
}

void PaymentUI::show_time_text()
{
    QDateTime time = QDateTime::currentDateTime();
    QString time_format = "HH:mm:ss";
    QString str_time = time.toString(time_format);

    QStringList input_big = input_time.split(":");
    //QStringList input_small = input_big.last().split(":");

    QStringList output_big = str_time.split(":");
    //QStringList output_small = output_big.last().split(":");

    int parking_send_fee = 0;
    int charging_send_fee = 0;

    if (parking_fee_data == 0)
        parking_send_fee = 1000;
    else
        parking_send_fee = parking_fee_data.toInt();

    if (charging_fee_data == 0)
        charging_send_fee = 1000;
    else
        charging_send_fee = charging_fee_data.toInt();

    int in_hh, in_mm, in_ss, in_time = 0;
    int out_hh, out_mm, out_ss, out_time = 0;
    int hour_sum, min_sum = 0;
    int hour_min_sum = 0;

    in_hh = input_big[0].toInt() * 3600;
    in_mm = input_big[1].toInt() * 60;
    in_ss = input_big[2].toInt();

    out_hh = output_big[0].toInt() * 3600;
    out_mm = output_big[1].toInt() * 60;
    out_ss = output_big[2].toInt();

    in_time = in_hh + in_mm + in_ss;
    out_time = out_hh + out_mm + out_ss;

    hour_sum = (((out_time - in_time)/3600) * parking_send_fee) + (((out_time - in_time)/3600) * charging_send_fee);
    min_sum = (((out_time - in_time)/60) * (parking_send_fee/10)) + (((out_time - in_time)/60) * (charging_send_fee/10));
    hour_min_sum = hour_sum + min_sum;

    QString all_sum = QString::number(hour_min_sum);

    ui->entry_time_line->setText(input_time);
    ui->departure_time_line->setText(str_time);
    ui->total_fee_line->setText(all_sum);
}


void PaymentUI::send_payment_data()
{
    QString temp;
    temp = car_num + "@" + phone_num + "@" + ui->departure_time_line->text();
    emit update_payment(temp);
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
