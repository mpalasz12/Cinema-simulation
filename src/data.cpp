#include "movie.h"
#include "data.h"
#include "two_d.h"
#include "three_d.h"
#include <iostream>

void DataBase::addMovie(std::string newName, unsigned int newPrice, unsigned int newDuration, unsigned short int newFrequency)
{
    if(movies.end() == findMovie(newName))
    {
        std::unique_ptr<Movie> added_movie = std::make_unique<Movie>(newName, newPrice, newDuration, newFrequency);
        movies.push_back(std::move(added_movie));
    }
}
void DataBase::addMovieTwoD(std::string newName, unsigned int newPrice, unsigned int newDuration, unsigned short int newFrequency)
{
    if(movies.end() == findMovie(newName))
    {
        std::unique_ptr<Movie> added_movie = std::make_unique<TwoDMovie>(newName, newPrice, newDuration, newFrequency);
        movies.push_back(std::move(added_movie));
    }
}
void DataBase::addMovieThreeD(std::string newName, unsigned int newPrice, unsigned int newDuration, unsigned short int newFrequency)
{
    if(movies.end() == findMovie(newName))
    {
        std::unique_ptr<Movie> added_movie = std::make_unique<ThreeDMovie>(newName, newPrice, newDuration, newFrequency);
        movies.push_back(std::move(added_movie));
    }
}
void DataBase::printMovies()
{
    for (const auto& movie : movies) 
    {
        std::cout << *movie << std::endl;
    }
}
void DataBase::removeMovie(std::string movieName)
{
    if(findMovie(movieName) != movies.end())
    {
        movies.erase(findMovie(movieName));
        std::cout << "Movie was removed" << std::endl;
    }
    else
    {
        std::cout << "Movie with provided name was not found" << std::endl;
    }
}
std::vector<std::unique_ptr<Movie>>::iterator DataBase::findMovie(std::string movieName)
{
    for (auto it = movies.begin(); it != movies.end(); ++it) 
    {
        if ((*it) -> getName() == movieName) 
        {
            return it;
        }
    }
    return movies.end();
}
