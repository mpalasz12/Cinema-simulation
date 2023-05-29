#include "customer.h"

Customer::Customer(std::string newName, unsigned int newAge, std::string newMovieName):
    name(newName),
    age(newAge),
    movieName(newMovieName)
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