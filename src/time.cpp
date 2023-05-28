#include "time.h"
#include "enums.hpp"
#include <string>
#include <ostream>

Time::Time(Weekday newDay, int newHour):
    day(newDay),
    hour(newHour)
{};

Weekday Time::getDay()
{
    return day;
}
int Time::getHour()
{
    return hour;
}
void Time::setDay(Weekday newDay)
{
    day = newDay;
}
void Time::setHour(int newHour)
{
    hour = newHour;
}
std::ostream& operator<<(std::ostream& os, const Time& time)
{   
    os << time.hour << ":00";
    return os;
}
