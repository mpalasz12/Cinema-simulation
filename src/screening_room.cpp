#include "screening_room.h"
#include "time.h"
#include "random_movies.h"
#include <string>
#include <iostream>

ScreeningRoom::ScreeningRoom(std::string newName, int newCapacity):
    name(newName),
    capacity(newCapacity)
{}
std::string ScreeningRoom::getName()
{
    return name;
}
int ScreeningRoom::getCapacity()
{
    return capacity;
}
std::vector<Showing>& ScreeningRoom::getSchedule(int index)
{
    return schedule[index];
}
void ScreeningRoom::fillSchedule(unsigned short opening, unsigned short closing)
{
    for(int i=0; i<7; i++)
    {
        Weekday day;
        switch (i) 
        {
        case 0:
            day = Weekday::Monday;
            break;
        case 1:
            day = Weekday::Tuesday;
            break;
        case 2:
            day = Weekday::Wednesday;
            break;
        case 3:
            day = Weekday::Thursday;
            break;
        case 4:
            day = Weekday::Friday;
            break;
        case 5:
            day = Weekday::Saturday;
            break;
        case 6:
            day = Weekday::Sunday;
            break;
        }
        Movie movie = randomMovie();
        int limit = opening;
        Time time(day, limit);
        Showing added_show(movie.getName(), time, movie.getDuration(), movie.getPrice());
        added_show.setFreeChairs(capacity);
        schedule[i].push_back(added_show);
        while(limit + added_show.getLength() <= closing)
        {
            limit += added_show.getLength();
            movie = randomMovie();
            time = Time(day, limit);
            added_show = Showing(movie.getName(), time, movie.getDuration(), movie.getPrice());
            added_show.setFreeChairs(capacity);
            schedule[i].push_back(added_show);
        }
    }
}
void ScreeningRoom::printSchedule()
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << std::endl;
        switch (i)
        {
            case 0:
                std::cout << "Monday: " << std::endl;
                std::cout << std::endl;
                break;
            case 1:
                std::cout << "Tuesday: " << std::endl;
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "Wednesday: " << std::endl;
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Thursday: " << std::endl;
                std::cout << std::endl;
                break;
            case 4:
                std::cout << "Friday: " << std::endl;
                std::cout << std::endl;
                break;
            case 5:
                std::cout << "Saturday: " << std::endl;
                std::cout << std::endl;
                break;
            case 6:
                std::cout << "Sunday: " << std::endl;
                std::cout << std::endl;
                break;
        }
        for (size_t x = 0; x < schedule[i].size(); x++)  // Poprawione i -> x
        {
            std::cout << schedule[i][x];
        }
    }
}

std::ostream& operator<<(std::ostream& os, const ScreeningRoom& screeningRoom)
{
    os <<"Rooms name: " << screeningRoom.name << std::endl
    << "Rooms maximum capacity: " << screeningRoom.capacity << std::endl;
    return os;
}