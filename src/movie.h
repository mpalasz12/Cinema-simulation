#include<string>
#include<vector>
#include "time.h"
#pragma once

class Movie
{
protected:
    std::string name;
    double price;
    unsigned int duration;
    unsigned short int frequency;
    std::vector<Time> times;

public:
    Movie(std::string newName, double newPrice, unsigned int newDuration,
    unsigned short int newFrequency);

    std::string getName();
    double getPrice();
    unsigned int getDuration();
    unsigned short int getFrequency();
    unsigned int getHowManyTimes();
    std::vector<Time>::iterator findElement(Time element);
    void addTimes(weekDay newDay, std::string newHour);
    void sortTimes();

    virtual double calculate_price() const;
    virtual unsigned short int calculate_frequency() const;

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
}; 