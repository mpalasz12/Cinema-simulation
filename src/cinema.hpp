#pragma once
#include <string>
#include <vector>
#include "register.hpp"
#include "data.h"
#include "enums.hpp"
#include "workplace.hpp"


/*! TODO: add class fields related to other cinema classes
 *  \todo add class fields related to other cinema classes
 */

class Cinema {
	private:
		std::string name;
		unsigned short openingHour;
		unsigned short closingHour;

		Register employees;
		DataBase moviesInfo;

		std::vector<Workplace> otherWorkplaces;
		std::vector<Workplace> ticketCounters;
		std::vector<Workplace> foodCounters;
		std::vector<Workplace> janitorClosets;

		std::vector<Workplace>::iterator findTicketCounter(unsigned ID);
		std::vector<Workplace>::iterator findFoodCounter(unsigned ID);
		std::vector<Workplace>::iterator findCloset(unsigned ID);
		std::vector<Workplace>::iterator findOther(unsigned ID);

		std::vector<Workplace>::iterator findWorkplace(unsigned ID, WorkplaceType type);
	public:
		Cinema(std::string name, unsigned short opening, unsigned short closing);

		std::string getName();
		void setName(std::string newName);

		unsigned short getOpeningHour();
		unsigned short getClosingHour();
		void setOpeningHour(unsigned short hour);
		void setClosingHour(unsigned short hour);

		void addEmployee(std::string name, employeeType type, unsigned short hours);

		void addTicketCounter();
		void addFoodCounter();
		void addJanitorCloset();

		bool tCounterHasEmployee(unsigned ID);

		void prepareWorkplacesDay(Weekday day);
		void prepareEmployeeSchedules();

		void addAvailabilityForAll(Weekday day);

};
