#include "movie.h"
#include<vector>
#include <memory>
#pragma once

class DataBase
{
private:
    std::vector<std::unique_ptr<Movie>> movies;
public:
    void addMovie(std::string newName, unsigned int newPrice, unsigned int newDuration, unsigned short int newFrequency);
    void addMovieTwoD(std::string newName, unsigned int newPrice, unsigned int newDuration, unsigned short int newFrequency);
    void addMovieThreeD(std::string newName, unsigned int newPrice, unsigned int newDuration, unsigned short int newFrequency);
    void printMovies();
    void removeMovie(std::string movieName);

    std::vector<std::unique_ptr<Movie>>::iterator findMovie(std::string movieName);
};