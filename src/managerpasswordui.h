#ifndef MANAGERPASSWORDUI_H
#define MANAGERPASSWORDUI_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class ManagerPasswordUI;
}

class ManagerPasswordUI : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerPasswordUI(QWidget *parent = nullptr);
    ~ManagerPasswordUI();

signals:

    void manager_view();

private:
    Ui::ManagerPasswordUI *ui;
    QMessageBox password_error_msg;
    QString button_pasword;
    int check_num;
private slots:
    void move_back();
    void move_manager_view();

};

#endif // MANAGERPASSWORDUI_H
