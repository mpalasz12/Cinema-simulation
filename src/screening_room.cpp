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
void ScreeningRoom::fillSchedule()
{
    for(int i=0; i<7; i++)
    {
        weekDay day;
        switch (i) 
        {
        case 0:
            day = Monday;
            break;
        case 1:
            day = Tuesday;
            break;
        case 2:
            day = Wednesday;
            break;
        case 3:
            day = Thursday;
            break;
        case 4:
            day = Friday;
            break;
        case 5:
            day = Saturday;
            break;
        case 6:
            day = Sunday;
            break;
        }
        Movie movie = randomMovie();
        int limit = 8;
        Time time(day, limit);
        Showing added_show(movie.getName(), time, movie.getDuration(), movie.getPrice());
        added_show.setFreeChairs(capacity);
        schedule[i].push_back(added_show);
        while(limit + added_show.getLength() <= 20)
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