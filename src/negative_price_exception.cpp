#include "negative_price_exception.h"

NegativePriceException::NegativePriceException(double wrong_price):
std::invalid_argument("Negative value of the base price: " + std::to_string(wrong_price)){}
