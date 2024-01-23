#include "managermode.h"
#include "ui_managermode.h"

ManagerMode::ManagerMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerMode)
{
    ui->setupUi(this);
    connect(ui->pPBToMain, SIGNAL(clicked()), this, SLOT(push_to_mainui()));
}

void ManagerMode::push_to_mainui()
{
    emit push_to_main();
}

ManagerMode::~ManagerMode()
{
    delete ui;
}
