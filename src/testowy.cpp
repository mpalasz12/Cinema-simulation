#include "read_from_file.h"
#include <iostream>

int main()
{
    Cinema cinema = createCinema("cinema.txt");
    cinema.setScheduleForWeek("movies.txt");
    cinema.printSchedule();
    cinema.findShowings("Forrest Gump", 4);
    std::cout << "---------------------" << std::endl;
    cinema.printSchedule();
    addEmployeesFromFile(cinema, "workers.txt");
    
}