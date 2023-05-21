#pragma once
#include <stdexcept>

class NegativePriceException : public std::invalid_argument
{
    public: 
        NegativePriceException(double wrong_price);

};
