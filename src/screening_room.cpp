#include "screening_room.h"
#include <string>
#include <iostream>

ScreeningRoom::ScreeningRoom(std::string newName, int newCapacity):
    name(newName),
    capacity(newCapacity),
    freeChairs(newCapacity)
{}
std::string ScreeningRoom::getName()
{
    return name;
}
int ScreeningRoom::getCapacity()
{
    return capacity;
}
void ScreeningRoom::buyTickets(int howMany)
{
    if(freeChairs - howMany >= 0)
    {
        freeChairs = freeChairs - howMany;
    }
    else
    {
        std::cout << "Not enough free chairs" << std::endl;
    }
}
std::ostream& operator<<(std::ostream& os, const ScreeningRoom& screeningRoom)
{
    os <<"Rooms name: " << screeningRoom.name << std::endl
    << "Rooms maximum capacity: " << screeningRoom.capacity << std::endl
    << "Rooms free chairs: " << screeningRoom.freeChairs << std::endl;
    return os;
}