#include "read_from_file.h"

int main()
{
    Cinema cinema = createCinema("cinema.txt");
    cinema.setScheduleForWeek("movies.txt");
    cinema.printSchedule();
}