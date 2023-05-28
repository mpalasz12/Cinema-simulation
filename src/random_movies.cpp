#include "time.h"
#include "movie.h"
#include "data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>

int generateRandomNumber(int minRange, int maxRange)
{
    if (minRange > maxRange) {
        std::cerr << "Nieprawidłowy zakres liczb." << std::endl;
        return 0;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minRange, maxRange);
    return dis(gen);
}

Movie randomMovie()
{
    DataBase data;
    std::vector<std::string> lines;
    std::ifstream file("movies.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        std::cout << "Nie można otworzyć pliku." << std::endl;
    }

    int minRange = 0;
    int maxRange = lines.size() - 1;

    int randomNumber = generateRandomNumber(minRange, maxRange);

    std::istringstream iss(lines[randomNumber]);
    std::string newName;
    double newPrice;
    unsigned int newDuration;

    std::string field;

    std::getline(iss, field, ',');
    newName = field;

    std::getline(iss, field, ',');
    newPrice = std::stod(field);

    std::getline(iss, field, ',');
    newDuration = std::stoul(field);

    Movie movie(newName, newPrice, newDuration);

    return movie;
}
