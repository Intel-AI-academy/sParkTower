#ifndef MANAGERPASSWORDUI_H
#define MANAGERPASSWORDUI_H

#include <QWidget>

namespace Ui {
class ManagerPasswordUI;
}

class ManagerPasswordUI : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerPasswordUI(QWidget *parent = nullptr);
    ~ManagerPasswordUI();

private:
    Ui::ManagerPasswordUI *ui;

};

#endif // MANAGERPASSWORDUI_H
