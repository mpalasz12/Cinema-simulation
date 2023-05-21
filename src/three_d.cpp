#include <string>
#include "three_d.h"

ThreeDMovie::ThreeDMovie(std::string newName, double newPrice,
unsigned int newDuration, unsigned short int newFrequency):
Movie(newName, newPrice, newDuration, newFrequency)
{}
double ThreeDMovie::calculate_price() const
{
    return price + 2;
}