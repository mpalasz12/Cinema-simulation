#include "time.h"
#include <string>
#include <ostream>

Time::Time(weekDay newDay, int newHour):
    day(newDay),
    hour(newHour)
{};

weekDay Time::getDay()
{
    return day;
}
int Time::getHour()
{
    return hour;
}
void Time::setDay(weekDay newDay)
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
