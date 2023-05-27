#pragma once
#include <string>
#include <vector>
#include <memory>
#include "showing.h"

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

    void fillSchedule();
    void printSchedule();

    friend std::ostream& operator<<(std::ostream& os, const ScreeningRoom& screeningRoom);
};