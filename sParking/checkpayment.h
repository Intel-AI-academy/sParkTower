#ifndef CHECKPAYMENT_H
#define CHECKPAYMENT_H

#include <QWidget>

namespace Ui {
class CheckPayMent;
}

class CheckPayMent : public QWidget
{
    Q_OBJECT

public:
    explicit CheckPayMent(QWidget *parent = nullptr);
    ~CheckPayMent();

private:
    Ui::CheckPayMent *ui;
};

#endif // CHECKPAYMENT_H
