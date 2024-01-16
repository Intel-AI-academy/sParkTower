#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H
#include <QWidget>
#include <QDateTime>
#include <QDebug>
#include "timer.h"

class TimeManager
{
public:

    TimeManager(const Timer &cur_time);

    ~TimeManager();

    void update_time(const Timer &new_time);

    void get_time(Timer &cur_time);

    void set_time(const Timer &new_time);

    void load_time(const Timer &new_time);

private:
    Timer internal_time;
};

#endif // TIMEMANAGER_H
