#include<string>
#include<vector>
#pragma once


class Movie
{
protected:
    std::string name;
    double price;
    unsigned int duration;
    unsigned short int frequency;
    std::vector<std::string> times;

public:
    Movie(std::string newName, double newPrice, unsigned int newDuration,
    unsigned short int newFrequency);

    std::string getName();
    double getPrice();
    unsigned int getDuration();
    unsigned short int getFrequency();
    std::vector<std::string>::iterator findElement(std::string element);
    void addTimes(std::string newTime);
    void sortTimes();

    virtual double calculate_price() const;
    virtual unsigned short int calculate_frequency() const;

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
}; 