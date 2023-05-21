#include<string>
#include<iostream>
#include <algorithm>
#include "movie.h"
#include "time.h"

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
unsigned int Movie::getHowManyTimes()
{
    return times.size();
}
std::vector<Time>::iterator Movie::findElement(Time element)
{
    for (auto it = times.begin(); it != times.end(); ++it) 
    {
        if (it->getDay() == element.getDay() && it->getHour() == element.getHour())
        {
            return it;
        }
    }
    return times.end();
}
void Movie::addTimes(weekDay newDay, std::string newHour)
{
    Time time(newDay, newHour);
    if(times.end() == findElement(time))
    {
        Time newTime(newDay, newHour);
        times.push_back(newTime);
    }
    sortTimes();
}
void Movie::sortTimes()
{
    std::sort(times.begin(), times.end(), 
    [](Time& time1, Time& time2) 
    {
        return time1.getDay() < time2.getDay();
    });

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
    << "Movie is played " << movie.calculate_frequency() << " times a week" << std::endl
    << "Movies starting hours: " << std::endl;
    for (const Time& time : movie.times)
    {
        os << " " << time;
    }
    return os;
}