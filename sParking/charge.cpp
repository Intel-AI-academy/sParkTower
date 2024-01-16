#include "charge.h"

Charge::Charge()
{

}

Charge::~Charge()
{

}

int Charge::get_parking_fee() {

        return parking_fee;
}

void Charge::set_parking_fee(int newParkingFee) {


        parking_fee = newParkingFee;
}

int Charge::get_charging_fee() {

        return charging_fee;
}

void Charge::set_charging_fee(int newChargingFee) {

        charging_fee = newChargingFee;
}
