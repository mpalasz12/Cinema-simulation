#pragma once
#include "cinema.hpp"

Cinema createCinema(std::string path);
void addEmployeesFromFile(Cinema& cinema, std::string path);
employeeType convertToEmployeeType(const std::string& employeeTypeName);