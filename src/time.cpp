#include "time.h"
#include "enums.hpp"
#include <string>
#include <ostream>

Time::Time(Weekday newDay, unsigned int newHour):
    day(newDay),
    hour(newHour)
{};

Weekday Time::getDay()
{
    return day;
}
unsigned int Time::getHour()
{
    return hour;
}
void Time::setDay(Weekday newDay)
{
    day = newDay;
}
void Time::setHour(unsigned int newHour)
{
    hour = newHour;
}

void Time::increaseHour() {
	hour++;
}

std::string Time::timeToString() {
	std::string result = std::to_string(hour);
	result.append(":00");
	switch (day) {
		case Weekday::Monday:
			result.append(" Monday");
			break;
		case Weekday::Tuesday:
			result.append(" Tuesday");
			break;
		case Weekday::Wednesday:
			result.append(" Wednesday");
			break;
		case Weekday::Thursday:
			result.append(" Thursday");
			break;
		case Weekday::Friday:
			result.append(" Friday");
			break;
		case Weekday::Saturday:
			result.append(" Saturday");
			break;
		case Weekday::Sunday:
			result.append(" Sunday");
			break;
		
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{   
    os << time.hour << ":00";
    return os;
}
