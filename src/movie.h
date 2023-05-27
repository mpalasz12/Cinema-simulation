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

public:
    Movie(std::string newName, double newPrice, unsigned int newDuration);
    Movie();

    std::string getName();
    double getPrice();
    unsigned int getDuration();
    void setName(std::string newName);
    void setPrice(double newPrice);
    void setDuration(unsigned int newDuration);

    virtual double calculate_price() const;

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    friend std::istream& operator>>(std::istream& is, Movie& movie);
}; 
