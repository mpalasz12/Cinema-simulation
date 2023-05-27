#include<string>
#include<iostream>
#include <algorithm>
#include "movie.h"
#include "time.h"

Movie::Movie(std::string newName, double newPrice,
unsigned int newDuration):
    name(newName),
    price(newPrice),
    duration(newDuration)
{}
Movie::Movie()
{}
std::string Movie::getName()
{
    return name;
}
double Movie::getPrice()
{
    return price;
}
unsigned int Movie::getDuration()
{
    return duration;
}
void Movie::setName(std::string newName)
{
    name = newName;
}
void Movie::setPrice(double newPrice)
{
    price = newPrice;
}
void Movie::setDuration(unsigned int newDuration)
{
    duration = newDuration;
}
double Movie::calculate_price() const
{
    return price;
}
std::ostream& operator<<(std::ostream& os, const Movie& movie)
{
    os <<"Movies name: " << movie.name << std::endl
    << "Movies price: " << movie.calculate_price() << std::endl
    << "Movies length: " << movie.duration << " minutes" << std::endl;
    return os;
}
std::istream& operator>>(std::istream& is, Movie& movie)
{
    std::string newName;
    double newPrice;
    unsigned int newDuration;

    std::getline(is, newName);

    is >> newPrice >> newDuration;

    movie.setName(newName);
    movie.setPrice(newPrice);
    movie.setDuration(newDuration);

    return is;
}