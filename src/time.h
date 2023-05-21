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
    std::string hour;
public:
    Time(weekDay newDay, std::string newHour);

    weekDay getDay();
    std::string getHour();

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};
std::ostream& operator<<(std::ostream& os, const Time& time);