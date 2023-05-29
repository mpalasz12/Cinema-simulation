#include "read_from_file.h"
#include <fstream>
#include <sstream>
#include <iostream>

Cinema createCinema(std::string path)
{
    std::ifstream file(path);
    if (file.is_open()) 
    {
        std::string line;
        std::string field;
        std::string name;
        unsigned short opening;
        unsigned short closing;
        std::getline(file, line);
        std::istringstream iss(line);

        std::getline(iss, field, ',');
        name = field;

        std::getline(iss, field, ',');
        opening = std::stoul(field);

        std::getline(iss, field, ',');
        closing = std::stoul(field);

        Cinema cinema(name, opening, closing);

        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::getline(iss, field, ',');
            std::string screeningRoomName = field;

            std::getline(iss, field, ',');
            unsigned short capacity = std::stoul(field);
            cinema.addScreeningRoom(screeningRoomName, capacity);
        }

        file.close();
        return cinema;
    }
    else {
        std::cout << "Can't open a file." << std::endl;
    }
    return Cinema("", 0,0);
}

void addEmployeesFromFile(Cinema& cinema, std::string path)
{
    std::ifstream file(path);
    if (file.is_open()) 
    {
        
    }
    else {
        std::cout << "Can't open a file." << std::endl;
    }
}