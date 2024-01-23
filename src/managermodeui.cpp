#include "managermodeui.h"
#include "ui_managermodeui.h"

ManagerModeUI::ManagerModeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerModeUI)
{
    ui->setupUi(this);

    p_chargemanagerdialog = new ChargeManagerDialog;
    p_garagemanagerdialog = new GarageManagerDialog;
    p_infodatabase = new InfoDatabase;

    yellow.load(":/icon/yellow.png");
    blue.load(":/icon/blue.png");
    ui->label_1->setPixmap(blue);
    ui->label_2->setPixmap(blue);
    ui->label_3->setPixmap(blue);
    ui->label_4->setPixmap(blue);

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(push_back_button()));
    connect(ui->charge_manager_button, SIGNAL(clicked()), this, SLOT(show_payment_manager_view()));
    connect(ui->garage_manager_button, SIGNAL(clicked()), this, SLOT(show_garage_view()));
    connect(p_chargemanagerdialog, SIGNAL(send_fee(QString, QString)), this, SLOT(show_signal(QString, QString)));

}

void ManagerModeUI::push_back_button()
{
    emit push_back();
}

void ManagerModeUI::show_payment_manager_view()
{
    p_chargemanagerdialog->show();
}

void ManagerModeUI::show_garage_view()
{
    p_garagemanagerdialog->show();
    p_garagemanagerdialog->garage_search_slot();
}

void ManagerModeUI::search_slot()
{
    int row_count = 0;
    QString str_query = "select * from parking_log_tb";
    QSqlQuery sql_query;

    if (!sql_query.exec(str_query)) {
        ;
    } else {
        while (sql_query.next()) {
            row_count++;

            ui->gararge_table->setRowCount(row_count);

            QTableWidgetItem *q_table_widget_item_car_num = new QTableWidgetItem();
            QTableWidgetItem *q_table_widget_item_input_time = new QTableWidgetItem();
            QTableWidgetItem *q_table_widget_item_output_time = new QTableWidgetItem(); //ex
            QTableWidgetItem *q_table_widget_item_charge_check = new QTableWidgetItem();

            q_table_widget_item_car_num->setText(sql_query.value("car_num").toString());
            q_table_widget_item_input_time->setText(sql_query.value("input_time").toString());
            q_table_widget_item_output_time->setText(sql_query.value("output_time").toString());
            q_table_widget_item_charge_check->setText(sql_query.value("charge_check").toString());

            ui->gararge_table->setItem(row_count - 1, 0, q_table_widget_item_car_num);
            ui->gararge_table->setItem(row_count - 1, 1, q_table_widget_item_input_time);
            ui->gararge_table->setItem(row_count - 1, 2, q_table_widget_item_output_time);
            ui->gararge_table->setItem(row_count - 1, 3, q_table_widget_item_charge_check);

            ui->gararge_table->horizontalHeader()->setStretchLastSection(true); // resize test

            if(sql_query.value("car_slot_num").toInt() == 1 && sql_query.value("output_time").toString() == "null")
                ui->label_1->setPixmap(yellow);
            else if(sql_query.value("car_slot_num").toInt() == 2 && sql_query.value("output_time").toString() == "null")
                ui->label_2->setPixmap(yellow);
            else if(sql_query.value("car_slot_num").toInt() == 3 && sql_query.value("output_time").toString() == "null")
                ui->label_3->setPixmap(yellow);
            else if(sql_query.value("car_slot_num").toInt() == 3 && sql_query.value("output_time").toString() == "null")
                ui->label_4->setPixmap(yellow);
            else if(sql_query.value("car_slot_num").toInt() == 1 && sql_query.value("output_time").toString() != "null")
                ui->label_1->setPixmap(blue);
            else if(sql_query.value("car_slot_num").toInt() == 2 && sql_query.value("output_time").toString() != "null")
                ui->label_2->setPixmap(blue);
            else if(sql_query.value("car_slot_num").toInt() == 3 && sql_query.value("output_time").toString() != "null")
                ui->label_3->setPixmap(blue);
            else if(sql_query.value("car_slot_num").toInt() == 4 && sql_query.value("output_time").toString() != "null")
                ui->label_4->setPixmap(blue);
        }
    }
}

void ManagerModeUI::show_signal(QString parking_fee, QString charging_fee){

    emit send_fee_text(parking_fee, charging_fee);
}

ManagerModeUI::~ManagerModeUI()
{
    delete ui;
}
