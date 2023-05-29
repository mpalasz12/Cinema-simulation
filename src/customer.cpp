#include "customer.h"

Customer::Customer(std::string newName, unsigned int newAge, std::string newMovieName, unsigned int newHowManyTickets):
    name(newName),
    age(newAge),
    movieName(newMovieName),
    howManyTickets(newHowManyTickets)
{}
std::string Customer::getName()
{
    return name;
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
void Customer::setName(std::string newName)
{
    name = newName;
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