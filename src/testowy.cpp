#include "cinema.hpp"
#include "read_from_file.h"
#include "simlog.hpp"
#include <iostream>
#include <vector>

int main()
{
    Cinema cinema("nazwa", 10, 20);
    cinema.addRoomsFromFile("cinema.txt");
    cinema.setScheduleForWeek("movies.txt");
    cinema.printSchedule();
    Time time(Weekday::Monday, 14);
    std::vector<std::string> movies = cinema.getNamesOfMovies(time);
    for (const std::string& movie : movies) 
    {
        std::cout << movie << std::endl;
    }
}