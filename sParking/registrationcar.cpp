#include "registrationcar.h"
#include "ui_registrationcar.h"

RegistrationCar::RegistrationCar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationCar)
{
    ui->setupUi(this);
}

RegistrationCar::~RegistrationCar()
{
    delete ui;
}
