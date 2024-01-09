#include "parkinginfo.h"

ParkingInfo::ParkingInfo()
{

}

ParkingInfo::~ParkingInfo()
{

}

int ParkingInfo::get_total_space() {

        return total_space;
}

int ParkingInfo::get_occupied_space() {

        return occupied_space;
}

int ParkingInfo::get_available_space() {

        return available_space;
}

void ParkingInfo::inc_occupied_space() {

        occupied_space++;
}

void ParkingInfo::dec_occupied_space() {

        occupied_space--;
}

void ParkingInfo::inc_available_space() {

        available_space++;
}

void ParkingInfo::dec_available_space() {

        available_space--;
}
