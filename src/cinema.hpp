#pragma once
#include <string>
#include <vector>
#include <memory>
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
		unsigned short openingHour;
		unsigned short closingHour;
		std::string name;

		Register employees;
		std::vector<ScreeningRoom> screeningRooms;

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

		void prepareWorkplacesDay(Weekday day);
		void addScreeningRoom(std::string newName, int newCapacity);
		void setScheduleForWeek();

		void buyTickets(std::string roomName, std::string movieName, weekDay day, int hour, int numberOfTickets);

		Register getRegister();

};
