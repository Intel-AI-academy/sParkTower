#ifndef PARKINGINFO_H
#define PARKINGINFO_H


class ParkingInfo
{
public:
    ParkingInfo();

    ~ParkingInfo();

    int get_total_space();

    int get_occupied_space();

    int get_available_space();

    void inc_occupied_space();

    void dec_occupied_space();

    void inc_available_space();

    void dec_available_space();

private:
    int total_space, occupied_space, available_space;
};

#endif // PARKINGINFO_H
