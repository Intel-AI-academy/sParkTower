#include "mainui.h"
#include "ui_mainui.h"

MainUI::MainUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainUI)
{
    ui->setupUi(this);

    p_usermode = new UserModeUI;
    p_managerMode = new ManagerModeUI;

    ui->stackedWidget->insertWidget(1, p_usermode);
    ui->stackedWidget->insertWidget(2, p_managerMode);


    connect(ui->user_mode, SIGNAL(clicked()), this, SLOT(push_usermode()));
    connect(ui->manager_mode, SIGNAL(clicked()), this, SLOT(push_managermode()));

    connect(p_usermode, SIGNAL(push_back()), this, SLOT(push_usermode_back()));
    connect(p_managerMode, SIGNAL(push_back()), this, SLOT(push_managermode_back()));

}

void MainUI::push_usermode()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainUI::push_managermode()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainUI::push_usermode_back()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainUI::push_managermode_back()
{
    ui->stackedWidget->setCurrentIndex(0);
}

MainUI::~MainUI()
{
    delete ui;
}
