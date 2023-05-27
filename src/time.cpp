#include "time.h"
#include <string>
#include <ostream>

Time::Time(Weekday newDay, std::string newHour):
    day(newDay),
    hour(newHour)
{};

Weekday Time::getDay()
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
	case Weekday::Monday:
        os << "Monday: ";
        break;
	case Weekday::Tuesday:
        os << "Tuesday: ";
        break;
	case Weekday::Wednesday:
        os << "Wednesday: ";
        break;
	case Weekday::Thursday:
        os << "Thursday: ";
        break;
	case Weekday::Friday:
        os << "Friday: ";
        break;
	case Weekday::Saturday:
        os << "Saturday: ";
        break;
	case Weekday::Sunday:
        os << "Sunday: ";
        break;
    }
    os << time.hour << std::endl;
    return os;
}
