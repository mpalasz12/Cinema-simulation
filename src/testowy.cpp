#include "cinema.hpp"
#include <iostream>

int main()
{
    Cinema cinema("nazwa1", 7, 30);
    cinema.addScreeningRoom("sala1", 20);
    cinema.setScheduleForWeek();
    cinema.printSchedule();
    std::cout << "----------------" << std::endl;
    cinema.findShowings("Forrest", 3);
    cinema.printSchedule();
}