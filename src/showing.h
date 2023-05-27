#pragma once
#include <string>
#include "time.h"

class Showing
{
private:
    std::string name;
    Time date;
    unsigned int length;
    int freeChairs;
    double price;
public:
    Showing(std::string newName, Time newDate, int newLength, double newPrice);

    std::string getName();
    int getLength();
    double getPrice();

    void setFreeChairs(int newFreeChairs);

    friend std::ostream& operator<<(std::ostream& os, const Showing& showing);
};
std::ostream& operator<<(std::ostream& os, const Showing& showing);