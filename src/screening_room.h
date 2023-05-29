#pragma once
#include <string>
#include <vector>
#include <memory>
#include "showing.h"
#include "enums.hpp"

class ScreeningRoom
{
private:
    std::string name;
    int capacity;
    std::vector<Showing> schedule[7];
public:
    ScreeningRoom(std::string newName, int newCapacity);

    std::string getName();
    int getCapacity();
    std::vector<Showing>& getSchedule(int index);

    void fillSchedule(unsigned short openinig, unsigned short closing);
    void printSchedule();

    friend std::ostream& operator<<(std::ostream& os, const ScreeningRoom& screeningRoom);
};