#include<string>
#pragma once
#include "enums.hpp"

class Time
{
private:
    Weekday day;
    unsigned int hour;
public:
    Time(Weekday newDay, unsigned int newHour);

    Weekday getDay();
    unsigned int getHour();

	void setDay(Weekday newDay);
	void setHour(unsigned int newHour);
	
	void increaseHour();
	std::string timeToString();

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};
std::ostream& operator<<(std::ostream& os, const Time& time);
