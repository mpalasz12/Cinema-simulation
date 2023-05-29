#pragma once
#include <string>

class Customer
{
private:
    std::string name;
    unsigned int age;
    std::string movieName;
public:
    Customer(std::string newName, unsigned int newAge, std::string newMovieName);;

    std::string getName();
    unsigned int getAge();
    std::string getMovieName();

    void setName(std::string newName);
    void setAge(unsigned int newAge);
    void setMovieName(std::string newMovieName);
};