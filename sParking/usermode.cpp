#include "usermode.h"
#include "ui_usermode.h"

UserMode::UserMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserMode)
{
    ui->setupUi(this);

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(push_to_main()));
}

void UserMode::push_to_main()
{
    emit push_back();
}

UserMode::~UserMode()
{
    delete ui;
}
