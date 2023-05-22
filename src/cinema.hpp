#pragma once
#include <string>
#include <vector>
#include <memory>
#include "register.hpp"
#include "data.h"
#include "enums.hpp"


/*! TODO: add class fields related to other cinema classes
 *  \todo add class fields related to other cinema classes
 */

class Cinema {
	private:
		std::string name;
		Register employees;
		DataBase moviesInfo;
	public:
		Cinema(std::string name);

		std::string getName();
		void setName(std::string newName);

		void addEmployee(std::string name, employeeType type, unsigned short hours);

		Register getRegister();

};
