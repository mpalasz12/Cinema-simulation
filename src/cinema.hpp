#pragma once
#include <string>
#include <vector>
#include "register.hpp"
#include "data.h"
#include "enums.hpp"
#include "workplace.hpp"
#include "screening_room.h"


/*! TODO: add class fields related to other cinema classes
 *  \todo add class fields related to other cinema classes
 */

class Cinema {
	private:
		// class fields
		std::string name;
		unsigned short openingHour;
		unsigned short closingHour;

		Register employees;
		std::vector<ScreeningRoom> screeningRooms;

		std::vector<Workplace> otherWorkplaces;
		std::vector<Workplace> ticketCounters;
		std::vector<Workplace> foodCounters;
		std::vector<Workplace> janitorClosets;

		// private methods
		std::vector<Workplace>::iterator findWorkplace(unsigned ID, WorkplaceType type);
		std::vector<Workplace>& getWorkplaceVec(WorkplaceType type);
	public:

		// constructor(s)
		Cinema(std::string name, unsigned short opening, unsigned short closing);

		// getters, setters
		std::string getName();
		void setName(std::string newName);

		unsigned short getOpeningHour();
		unsigned short getClosingHour();
		void setOpeningHour(unsigned short hour);
		void setClosingHour(unsigned short hour);

		// collection manipulation
		void addEmployee(std::string name, employeeType type, unsigned short hours);

		void addTicketCounter();
		void addFoodCounter();
		void addJanitorCloset();

		bool isWorkplace(unsigned ID, WorkplaceType type);
		bool hasEmployee(unsigned ID, WorkplaceType type);

		// simulation related methods
		void prepareWorkplacesDay(Weekday day);
		void addScreeningRoom(std::string newName, int newCapacity);
		void setScheduleForWeek();
		void printSchedule();

		void buyTickets(std::string roomName, std::string movieName, weekDay day, int hour, int numberOfTickets);

		void addAvailabilityForAll(Weekday day);

};
