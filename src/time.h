#include<string>
#pragma once
#include "enums.hpp"

class Time
{
private:
    Weekday day;
    int hour;
public:
    Time(Weekday newDay, int newHour);

    Weekday getDay();
    int getHour();

	void setDay(Weekday newDay);
	void setHour(int newHour);

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};
std::ostream& operator<<(std::ostream& os, const Time& time);
