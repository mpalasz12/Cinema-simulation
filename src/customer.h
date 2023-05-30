#pragma once
#include <string>

class Customer
{
private:
	unsigned ID;
    unsigned int age;
    std::string movieName;
    unsigned int howManyTickets;
public:
    Customer(unsigned int ID, unsigned int newAge, std::string newMovieName, unsigned int newHowManyTickets);

    unsigned getID();
    unsigned int getAge();
    std::string getMovieName();
    unsigned int getHowManyTickets();

    void setID(unsigned newValue);
    void setAge(unsigned int newAge);
    void setMovieName(std::string newMovieName);
    void setHowManyTickets(unsigned int newHowManyTickets);
};
