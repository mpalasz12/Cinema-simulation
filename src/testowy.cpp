#include "cinema.hpp"
#include <iostream>

int main()
{
    Cinema cinema("nazwa1", 7, 30);
    cinema.addScreeningRoom("sala1", 20);
    cinema.setScheduleForWeek();
    cinema.printSchedule();
    std::cout << "----------------" << std::endl;
    std::vector<Showing> result = cinema.findShowings("Forrest Gump");
    for (Showing& showing : result)
    {
        Weekday day = showing.getDay();
        switch (day) 
        {
        case Weekday::Monday:
            std::cout << "Monday" << std::endl;
            break;
        case Weekday::Tuesday:
            std::cout << "Tuesday" << std::endl;
            break;
        case Weekday::Wednesday:
            std::cout << "Wednesday" << std::endl;
            break;
        case Weekday::Thursday:
            std::cout << "Thursday" << std::endl;
            break;
        case Weekday::Friday:
            std::cout << "Friday" << std::endl;
            break;
        case Weekday::Saturday:
            std::cout << "Saturday" << std::endl;
            break;
        case Weekday::Sunday:
            std::cout << "Sunday" << std::endl;
            break;
        }
        std::cout << showing;
    }    
}