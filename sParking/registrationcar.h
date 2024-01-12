#ifndef REGISTRATIONCAR_H
#define REGISTRATIONCAR_H

#include <QWidget>

namespace Ui {
class RegistrationCar;
}

class RegistrationCar : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationCar(QWidget *parent = nullptr);
    ~RegistrationCar();

private:
    Ui::RegistrationCar *ui;
};

#endif // REGISTRATIONCAR_H
