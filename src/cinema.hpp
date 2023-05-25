#pragma once
#include <string>
#include <vector>
#include <memory>
#include "register.hpp"
#include "data.h"
#include "enums.hpp"
#include "workplace.hpp"


/*! TODO: add class fields related to other cinema classes
 *  \todo add class fields related to other cinema classes
 */

class Cinema {
	private:
		unsigned short openingHour;
		unsigned short closingHour;
		std::string name;

		Register employees;
		DataBase moviesInfo;

		std::vector<Workplace> ticketCounters;
		std::vector<Workplace> foodCounters;

	public:
		Cinema(std::string name);

		std::string getName();
		void setName(std::string newName);

		unsigned short getOpeningHour();
		unsigned short getClosingHour();
		void setOpeningHour(unsigned short hour);
		void setClosingHour(unsigned short hour);

		void addEmployee(std::string name, employeeType type, unsigned short hours);

		void prepareEmployees();

		Register getRegister();

};
