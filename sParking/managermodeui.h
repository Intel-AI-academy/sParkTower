#ifndef MANAGERMODEUI_H
#define MANAGERMODEUI_H

#include <QWidget>

namespace Ui {
class ManagerModeUI;
}

class ManagerModeUI : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerModeUI(QWidget *parent = nullptr);
    ~ManagerModeUI();
signals:
    void push_back();
private:
    Ui::ManagerModeUI *ui;
private slots:
    void push_back_button();
};

#endif // MANAGERMODEUI_H
