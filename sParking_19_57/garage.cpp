#include "garage.h"

Garage::Garage()
{

}

Garage::~Garage()
{

}

Car Garage::get_car() {


        return car;
}

void Garage::set_car(const Car& newCar) {

        car = newCar;

}

int Garage::get_garage_number() {

        return garage_number;
}

void Garage::set_garage_number(int newGarageNumber) {

        garage_number = newGarageNumber;
}

bool Garage::is_available() {

        return available;
}

void Garage::set_available(bool newAvailable) {

        available = newAvailable;
}
