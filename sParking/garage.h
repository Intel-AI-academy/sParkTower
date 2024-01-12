#ifndef GARAGE_H
#define GARAGE_H
#include "car.h"

class Garage
{
public:
    Garage();

    ~Garage();

    Car get_car();

    void set_car(const Car& newCar);

    int get_garage_number();

    void set_garage_number(int newGarageNumber);

    bool is_available();

    void set_available(bool newAvailable);

private:
    int garage_number;
    bool available;
    Car car;
};

#endif // GARAGE_H
