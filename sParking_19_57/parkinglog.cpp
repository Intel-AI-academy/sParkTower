#include "parkinglog.h"

ParkingLog::ParkingLog()
{

}

ParkingLog::~ParkingLog()
{


}

std::string ParkingLog::get_date() {

        return date;

}

void ParkingLog::set_date(const std::string& newDate) {

        date = newDate;
}

std::string ParkingLog::get_car_number() {

        return car_number;
}

void ParkingLog::set_car_number(const std::string& newCarNumber) {

        car_number = newCarNumber;
}

double ParkingLog::get_parking_charge() {

        return parking_charge;
}

void ParkingLog::set_parking_charge(double newParkingCharge) {

        parking_charge = newParkingCharge;
}

double ParkingLog::get_charging_charge() {

        return charging_charge;
}

void ParkingLog::set_charging_charge(double newChargingCharge) {

        charging_charge = newChargingCharge;
}

int ParkingLog::get_parking_time() {

        return parking_time;
}

void ParkingLog::set_parking_time(int newParkingTime) {

        parking_time = newParkingTime;
}
