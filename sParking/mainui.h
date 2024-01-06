#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QStackedWidget>
#include "usermodeui.h"
#include "managermodeui.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainUI; }
QT_END_NAMESPACE

class MainUI : public QWidget
{
    Q_OBJECT

public:
    MainUI(QWidget *parent = nullptr);
    ~MainUI();

private:
    Ui::MainUI *ui;
    UserModeUI *p_usermode;
    ManagerModeUI *p_managerMode;

private slots:
    void push_usermode();
    void push_managermode();
    void push_usermode_back();
    void push_managermode_back();


};
#endif // MAINUI_H
