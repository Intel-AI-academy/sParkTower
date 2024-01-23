#include "garagemanagerdialog.h"
#include "ui_garagemanagerdialog.h"

GarageManagerDialog::GarageManagerDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GarageManagerDialog)
{
    ui->setupUi(this);

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(close_dialog()));
}


void GarageManagerDialog::garage_search_slot()
{
    int row_count = 0;
    QString str_query = "select * from parking_log_tb";
    QSqlQuery sql_query;

    if (!sql_query.exec(str_query)) {
        //qDebug() << " x ";
    } else {
        //qDebug() << " o ";
        while (sql_query.next()) {

            row_count++;
            ui->information_table->setRowCount(row_count);

            QTableWidgetItem *q_table_widget_item_car_slot_num = new QTableWidgetItem();
            QTableWidgetItem *q_table_widget_item_car_num = new QTableWidgetItem();
            QTableWidgetItem *q_table_widget_item_phone_num = new QTableWidgetItem();

            q_table_widget_item_car_slot_num->setText(sql_query.value("car_slot_num").toString());
            q_table_widget_item_car_num->setText(sql_query.value("car_num").toString());
            q_table_widget_item_phone_num->setText(sql_query.value("phone_num").toString());

            ui->information_table->setItem(row_count - 1, 0, q_table_widget_item_car_slot_num);
            ui->information_table->setItem(row_count - 1, 1, q_table_widget_item_car_num);
            ui->information_table->setItem(row_count - 1, 2, q_table_widget_item_phone_num);
        }
    }
    ui->information_table->horizontalHeader()->setStretchLastSection(true);
}


void GarageManagerDialog::close_dialog()
{

    close();
}

GarageManagerDialog::~GarageManagerDialog()
{
    delete ui;
}
