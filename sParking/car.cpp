#include "car.h"

Car::Car()
{

}

Car::~Car()
{

}

std::string Car::get_car_number() {

        return car_number;
}

void Car::set_car_number(const std::string& new_car_number) {

        car_number = new_car_number;
}

std::string Car::get_phone_number() {

        return phone_number;
}

void Car::set_phone_number(const std::string& new_phone_number) {

        phone_number = new_phone_number;
}

std::string Car::get_garage_number() {

        return garage_number;
}

void Car::set_garage_number(const std::string& new_garage_number) {

        garage_number = new_garage_number;
}

bool Car::is_parking_state() {

        return state;
}

void Car::set_state(bool new_state) {

        state = new_state;

}
