#include "usermodeui.h"
#include "ui_usermodeui.h"

UserModeUI::UserModeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserModeUI)
{
    ui->setupUi(this);

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(push_back_button()));
}

void UserModeUI::push_back_button()
{
    emit push_back();
}

UserModeUI::~UserModeUI()
{
    delete ui;
}
