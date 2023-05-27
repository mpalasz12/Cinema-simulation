#pragma once
#include <string>

class ScreeningRoom
{
private:
    std::string name;
    int capacity;
    int freeChairs;
public:
    ScreeningRoom(std::string newName, int newCapacity);

    std::string getName();
    int getCapacity();

    void buyTickets(int howMany);

    friend std::ostream& operator<<(std::ostream& os, const ScreeningRoom& screeningRoom);
};