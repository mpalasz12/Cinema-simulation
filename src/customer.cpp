#include "customer.h"

Customer::Customer(unsigned int ID, unsigned int newAge, std::string newMovieName, unsigned int newHowManyTickets):
    ID(ID),
    age(newAge),
    movieName(newMovieName),
    howManyTickets(newHowManyTickets)
{}
unsigned Customer::getID()
{
    return ID;
}
unsigned int Customer::getAge()
{
    return age;
}
std::string Customer::getMovieName()
{
    return movieName;
}
unsigned int Customer::getHowManyTickets()
{
    return howManyTickets;
}
void Customer::setID(unsigned newValue)
{
    ID = newValue;
}
void Customer::setAge(unsigned int newAge)
{
    age = newAge;
}
void Customer::setMovieName(std::string newMovieName)
{
    movieName = newMovieName;
}
void Customer::setHowManyTickets(unsigned int newHowManyTickets)
{
    howManyTickets = newHowManyTickets;
}
