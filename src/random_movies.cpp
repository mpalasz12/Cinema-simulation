#include "time.h"
#include "movie.h"
#include "data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<int> generateNonRepeatingRandomNumbers(int minRange, int maxRange, int count)
{
    if (count > (maxRange - minRange + 1)) {
        std::cerr << "Liczba losowań jest większa niż dostępny zakres liczb." << std::endl;
        return {};
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> availableNumbers(maxRange - minRange + 1);
    std::iota(availableNumbers.begin(), availableNumbers.end(), minRange);

    std::vector<int> result;
    for (int i = 0; i < count; ++i) {
        std::uniform_int_distribution<> dis(0, availableNumbers.size() - 1);
        int randomIndex = dis(gen);
        int randomNum = availableNumbers[randomIndex];
        result.push_back(randomNum);
        availableNumbers.erase(availableNumbers.begin() + randomIndex);
    }

    return result;
}
DataBase randomMovies(int howMany)
{
    DataBase data;
    std::vector<std::string> lines;
    std::ifstream file("movies.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
    }
    else
    {
        std::cout << "Can't open the file." << std::endl;
    }

    int minRange = 0;
    int maxRange = lines.size() - 1;
    int count = howMany;

    std::vector<int> randomNumbers = generateNonRepeatingRandomNumbers(minRange, maxRange, count);


    for(int i=0; i<count; i++)
    {
        std::istringstream iss(lines[randomNumbers[i]]);
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

        data.addMovie(newName, newPrice, newDuration);
    }
    return data;
}