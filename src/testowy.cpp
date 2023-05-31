#include "read_from_file.h"
#include "cinema.hpp"
#include "time.h"
#include <iostream>
#include <string>


int main()
{
    std::string logs;
    Cinema cinema = createCinema("cinema.txt");
    cinema.setScheduleForWeek("movies.txt");
    cinema.printSchedule();
    Time time(Weekday::Sunday, 8);
    logs = cinema.movieLogs(time);
    std::cout << logs;
    time.setHour(16);
    logs = cinema.movieLogs(time);
    std::cout << logs;
    cinema.addCountersFromFile("counter.txt");
    std::cout << logs;
}