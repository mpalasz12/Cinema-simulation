#include<string>
#pragma once
#include "enums.hpp"


class Time
{
private:
    Weekday day;
    std::string hour;
public:
    Time(Weekday newDay, std::string newHour);

    Weekday getDay();
    std::string getHour();

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};
std::ostream& operator<<(std::ostream& os, const Time& time);
