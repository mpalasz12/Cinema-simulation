#include<string>
#include<iostream>
#include <algorithm>
#include "movie.h"

Movie::Movie(std::string newName, double newPrice,
unsigned int newDuration, unsigned short int newFrequency):
    name(newName),
    price(newPrice),
    duration(newDuration),
    frequency(newFrequency)
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
unsigned short int Movie::getFrequency()
{
    return frequency;
}
std::vector<std::string>::iterator Movie::findElement(std::string element)
{
    for (auto it = times.begin(); it != times.end(); ++it) 
    {
        if (*it == element) {
            return it;
        }
    }
    return times.end();
}
void Movie::addTimes(std::string newTime)
{
    if(times.end() == findElement(newTime))
    {
        times.push_back(newTime);
    }
    sortTimes();
}
void Movie::sortTimes()
{
    std::sort(times.begin(), times.end());
}
double Movie::calculate_price() const
{
    return price;
}
unsigned short int Movie::calculate_frequency() const
{
    return frequency;
}
std::ostream& operator<<(std::ostream& os, const Movie& movie)
{
    os <<"Movies name: " << movie.name << std::endl
    << "Movies price: " << movie.calculate_price() << std::endl
    << "Movies length: " << movie.duration << " minutes" << std::endl
    << "Movie is played " << movie.calculate_frequency() << " times a day" << std::endl
    << "Movies starting hours: " << std::endl;
    for(const auto& element : movie.times)
    {
        os << element << std::endl;
    }
    return os;
}