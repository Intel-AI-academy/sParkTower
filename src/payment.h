#ifndef PAYMENT_H
#define PAYMENT_H

#include <QWidget>

namespace Ui {
class Payment;
}

class Payment : public QWidget
{
    Q_OBJECT

public:
    explicit Payment(QWidget *parent = nullptr);
    ~Payment();
signals:
    void push_to_usermode();
private:
    Ui::Payment *ui;
private slots:
    void push_to_usermodeui();
};

#endif // PAYMENT_H
