#include "garagemanagerdialog.h"
#include "ui_garagemanagerdialog.h"

GarageManagerDialog::GarageManagerDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GarageManagerDialog)
{
    ui->setupUi(this);

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(close_dialog()));
}

void GarageManagerDialog::close_dialog()
{

    close();
}

GarageManagerDialog::~GarageManagerDialog()
{
    delete ui;
}
