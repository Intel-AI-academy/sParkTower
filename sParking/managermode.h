#ifndef MANAGERMODE_H
#define MANAGERMODE_H

#include <QWidget>

namespace Ui {
class ManagerMode;
}

class ManagerMode : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerMode(QWidget *parent = nullptr);
    ~ManagerMode();
signals:
    void push_to_main();
private:
    Ui::ManagerMode *ui;
private slots:
    void push_to_mainui();
};

#endif // MANAGERMODE_H
