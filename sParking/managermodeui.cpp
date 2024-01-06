#include "managermodeui.h"
#include "ui_managermodeui.h"

ManagerModeUI::ManagerModeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerModeUI)
{
    ui->setupUi(this);
    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(push_back_button()));
}

void ManagerModeUI::push_back_button()
{
    emit push_back();
}

ManagerModeUI::~ManagerModeUI()
{
    delete ui;
}
