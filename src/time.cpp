#include "time.h"
#include <string>
#include <ostream>

Time::Time(weekDay newDay, std::string newHour):
    day(newDay),
    hour(newHour)
{};

weekDay Time::getDay()
{
    return day;
}
std::string Time::getHour()
{
    return hour;
}
std::ostream& operator<<(std::ostream& os, const Time& time)
{   
    switch (time.day) 
    {
    case 1:
        os << "Monday: ";
        break;
    case 2:
        os << "Tuesday: ";
        break;
    case 3:
        os << "Wednesday: ";
        break;
    case 4:
        os << "Thursday: ";
        break;
    case 5:
        os << "Friday: ";
        break;
    case 6:
        os << "Saturday: ";
        break;
    case 7:
        os << "Sunday: ";
        break;
    }
    os << time.hour << std::endl;
    return os;
}
