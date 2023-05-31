#include "cinema.hpp"

int main()
{
    Cinema cinema("nazwa", 8, 20);
    cinema.addEmployeesFromFile("workers.txt");
    
}