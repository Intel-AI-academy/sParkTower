#include "timer.h"

Timer::Timer()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    year = current_date_time.toString("yyyy").toStdString();
    month = current_date_time.toString("MM").toStdString();
    day = current_date_time.toString("dd").toStdString();
    hour = current_date_time.toString("hh").toStdString();
    min = current_date_time.toString("mm").toStdString();
    sec = current_date_time.toString("ss").toStdString();
}

Timer::~Timer()
{

}

std::string Timer::get_year() {

        return year;
}

void Timer::set_year(const std::string &new_year) {

        year = new_year;
}

std::string Timer::get_month() {

        return month;
}

void Timer::set_month(const std::string &new_month){

        month = new_month;
}

std::string Timer::get_day(){

    return day;
}

void Timer::set_day(const std::string &new_day){

    day = new_day;
}

std::string Timer::get_hour(){

    return hour;
}

void Timer::set_hour(const std::string &new_hour){

    hour = new_hour;
}

std::string Timer::get_min(){

    return min;

}

void Timer::set_min(const std::string &new_min){

    min = new_min;

}

std::string Timer::get_sec(){

    return sec;

}

void Timer::set_sec(const std::string &new_sec){

    sec = new_sec;

}
