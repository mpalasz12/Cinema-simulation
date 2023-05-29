#include "cinema.hpp"

int main()
{
    Cinema cinema("nazwa1", 7, 30);
    cinema.addScreeningRoom("sala1", 20);
    cinema.setScheduleForWeek();
    cinema.printSchedule();
}