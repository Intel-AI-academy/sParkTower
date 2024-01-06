#include "managerpasswordui.h"
#include "ui_managerpasswordui.h"

ManagerPasswordUI::ManagerPasswordUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerPasswordUI)
{
    ui->setupUi(this);

//    pManagerPasswordUI = new ManagerPasswordUI();
//    pManagerPasswordUI->show();


}

ManagerPasswordUI::~ManagerPasswordUI()
{
    delete ui;
}
