#ifndef USERMODE_H
#define USERMODE_H

#include <QWidget>

namespace Ui {
class UserMode;
}

class UserMode : public QWidget
{
    Q_OBJECT

public:
    explicit UserMode(QWidget *parent = nullptr);
    ~UserMode();

signals:
    void push_back();

private:
    Ui::UserMode *ui;
private slots:
    void push_to_main();
};

#endif // USERMODE_H
