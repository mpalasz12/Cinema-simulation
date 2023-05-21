#include "movie.h"
#pragma once

class TwoDMovie : public Movie
{
public:
    TwoDMovie(std::string newName, double newPrice, unsigned int newDuration,
    unsigned short int newFrequency);

    double calculate_price() const override;
    unsigned short int calculate_frequency() const override;
};