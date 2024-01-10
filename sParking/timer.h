#ifndef TIMER_H
#define TIMER_H
#include <iostream>

class Timer
{
public:
    Timer();

    ~Timer();

    std::string get_year();

    void set_year(const std::string& new_year);

    std::string get_month();

    void set_month(const std::string& new_month);

    std::string get_day();

    void set_day(const std::string& new_day);

    std::string get_hour();

    void set_hour(const std::string& new_hour);

    std::string get_min();

    void set_min(const std::string& new_min);

    std::string get_sec();

    void set_sec(const std::string& new_sec);

private:
    std::string year, month;
    std::string day, hour;
    std::string min, sec;
};

#endif // TIMER_H
