#include<string>
#pragma once

enum weekDay
{
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

class Time
{
private:
    weekDay day;
    int hour;
public:
    Time(weekDay newDay, int newHour);

    weekDay getDay();
    int getHour();

	void setDay(weekDay newDay);
	void setHour(int newHour);

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};
std::ostream& operator<<(std::ostream& os, const Time& time);