#pragma once
#include <string>
#include "time.h"
#include "enums.hpp"

class Showing
{
private:
    std::string name;
    Time date;
    unsigned int length;
    unsigned int freeChairs;
    double price;
public:
    Showing(std::string newName, Time newDate, int newLength, double newPrice);

    std::string getName();
    int getLength();
    unsigned int getFreeChairs();
    double getPrice();
    Weekday getDay();
    unsigned int getHour();

    void setFreeChairs(unsigned int newFreeChairs);

    friend std::ostream& operator<<(std::ostream& os, const Showing& showing);
};
std::ostream& operator<<(std::ostream& os, const Showing& showing);