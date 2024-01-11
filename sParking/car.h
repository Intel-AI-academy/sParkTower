#ifndef CAR_H
#define CAR_H

#include <iostream>

class Car
{
public:
    Car();

    ~Car();

    std::string get_car_number();

    void set_car_number(const std::string& new_car_number);

    std::string get_phone_number();

    void set_phone_number(const std::string& new_phone_number);

    std::string get_garage_number();

    void set_garage_number(const std::string& new_garage_number);

    bool is_parking_state();

    void set_state(bool new_state);

private:

    std::string car_number, phone_number, garage_number;
    bool state;

};

#endif // CAR_H
