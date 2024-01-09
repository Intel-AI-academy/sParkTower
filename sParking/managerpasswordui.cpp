#include "managerpasswordui.h"
#include "ui_managerpasswordui.h"

ManagerPasswordUI::ManagerPasswordUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerPasswordUI)
{
    ui->setupUi(this);

    connect(ui->back_button, SIGNAL(clicked()), this, SLOT(move_back()));
    connect(ui->check_button, SIGNAL(clicked()), this, SLOT(move_manager_view()));
}

void ManagerPasswordUI::move_back()
{
    close();
}

void ManagerPasswordUI::move_manager_view()
{
    if(ui->password_line->text() == "1")
    {
        close();
        emit manager_view();
    }
    else
    {
        password_error_msg.setText("Password Error!");
        password_error_msg.exec();
    }
}

ManagerPasswordUI::~ManagerPasswordUI()
{
    delete ui;
}
