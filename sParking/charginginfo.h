#ifndef CHARGINGINFO_H
#define CHARGINGINFO_H


class ChargingInfo
{
public:
    ChargingInfo();

    ~ChargingInfo();

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

#endif // CHARGINGINFO_H
