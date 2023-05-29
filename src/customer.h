#pragma once
#include <string>

class Customer
{
private:
    std::string name;
    unsigned int age;
    std::string movieName;
    unsigned int howManyTickets;
public:
    Customer(std::string newName, unsigned int newAge, std::string newMovieName, unsigned int newHowManyTickets);

    std::string getName();
    unsigned int getAge();
    std::string getMovieName();
    unsigned int getHowManyTickets();

    void setName(std::string newName);
    void setAge(unsigned int newAge);
    void setMovieName(std::string newMovieName);
    void setHowManyTickets(unsigned int newHowManyTickets);
};