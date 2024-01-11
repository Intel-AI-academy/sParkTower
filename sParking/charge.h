#ifndef CHARGE_H
#define CHARGE_H


class Charge
{
public:
    Charge();

    ~Charge();

    int get_parking_fee();

    void set_parking_fee(int new_parking_fee);

    int get_charging_fee();

    void set_charging_fee(int new_charging_fee);

private:

    int parking_fee, charging_fee;
};

#endif // CHARGE_H
