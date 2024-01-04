#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QStackedWidget>
#include "usermode.h"
#include "managermode.h"


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
    UserMode *p_usermode;
    ManagerMode *p_managerMode;

private slots:
    void push_usermode();
    void push_managermode();
    void push_usermode_back();
    void push_managermode_back();


};
#endif // MAINUI_H
