#ifndef PARKINGLOG_H
#define PARKINGLOG_H

#include <iostream>

class ParkingLog
{
public:
    ParkingLog();

    ~ParkingLog();

    std::string get_date();

    void set_date(const std::string& new_date);

    std::string get_car_number();

    void set_car_number(const std::string& new_car_number);

    double get_parking_charge();

    void set_parking_charge(double new_parking_charge);

    double get_charging_charge();

    void set_charging_charge(double new_charging_charge);

    int get_parking_time();

    void set_parking_time(int new_parking_time);

private:
    std::string date, car_number;
    double parking_charge, charging_charge;
    int parking_time, charging_time;
};

#endif // PARKINGLOG_H
