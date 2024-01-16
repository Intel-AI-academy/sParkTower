#include "timemanager.h"

TimeManager::TimeManager(const Timer &cur_time)
{
    this->update_time(cur_time);

}

TimeManager::~TimeManager()
{

}

void TimeManager::update_time(const Timer &new_time){

    internal_time = new_time;
}

void TimeManager::get_time(Timer &cur_time){

    cur_time = internal_time;

}

void TimeManager::set_time(const Timer &new_time){

    internal_time = new_time;

}

void TimeManager::load_time(const Timer &new_time){

    internal_time = new_time;

}
