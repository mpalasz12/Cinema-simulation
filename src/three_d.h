#include "movie.h"
#pragma once

class ThreeDMovie : public Movie
{
public:
    ThreeDMovie(std::string newName, double newPrice, unsigned int newDuration,
    unsigned short int newFrequency);

    double calculate_price() const override;
};