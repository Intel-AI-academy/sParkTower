#include "charginginfo.h"

ChargingInfo::ChargingInfo()
{

}

ChargingInfo::~ChargingInfo()
{

}

int ChargingInfo::get_total_space() {


        return total_space;
}

int ChargingInfo::get_occupied_space() {

        return occupied_space;

}

int ChargingInfo::get_available_space() {

        return available_space;
}

void ChargingInfo::inc_occupied_space() {

        occupied_space++;
}

void ChargingInfo::dec_occupied_space() {

        occupied_space--;
}

void ChargingInfo::inc_available_space() {

        available_space++;
}

void ChargingInfo::dec_available_space() {

        available_space--;
}
