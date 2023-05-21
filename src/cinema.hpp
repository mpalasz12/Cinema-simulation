#pragma once
#include <string>
#include <vector>
#include "register.hpp"


enum class employeeType {
	worker,
	ticketSeller,
	foodSeller,
	janitor,
};

/*! TODO: add class fields related to other cinema classes
 *  \todo add class fields related to other cinema classes
 */

class Cinema {
	private:
		std::string name;
		Register employees;
	public:
		Cinema(std::string name);

		std::string getName();
		void setName(std::string newName);

		void addEmployee(std::string name, employeeType type, unsigned short hours);

		Register getRegister();

};
