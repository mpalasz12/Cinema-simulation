#include "showing.h"
#include <iostream>

Showing::Showing(std::string newName, Time newDate, int newLength, double newPrice):
    name(newName),
    date(newDate),
    price(newPrice)
{
    int hours = newLength / 60;
    if(hours % 60 != 0)
    {
        hours++;
    }
    length = hours;
}
void Showing::setFreeChairs(int newFreeChairs)
{
    freeChairs = newFreeChairs;
}
std::string Showing::getName()
{
    return name;
}
int Showing::getLength()
{
    return length;
}
double Showing::getPrice()
{
    return price;
}
std::ostream& operator<<(std::ostream& os, const Showing& showing)
{
    os <<"Movies name: " << showing.name << std::endl
    << "Movies starting hour: " << showing.date << std::endl
    << "Movies price: " << showing.price << std::endl
    << "Free chairs: " << showing.freeChairs << std::endl << std::endl;
    return os;
}