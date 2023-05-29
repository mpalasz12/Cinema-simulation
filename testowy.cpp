#include "cinema.hpp"
#include "read_from_file.h"
#include <iostream>

int main()
{
    Cinema cinema = createCinema("cinema.txt");
    cinema.setScheduleForWeek("movies.txt");
    cinema.printSchedule();
}