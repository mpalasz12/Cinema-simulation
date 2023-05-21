#include <string>
#include <iostream>
#include "two_d.h"

TwoDMovie::TwoDMovie(std::string newName, double newPrice,
unsigned int newDuration, unsigned short int newFrequency):
Movie(newName, newPrice, newDuration, newFrequency)
{}
double TwoDMovie::calculate_price() const
{
    return 0.8 * price;
}
unsigned short int TwoDMovie::calculate_frequency() const
{
    return frequency * 2;
}