#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include "register.hpp"
#include "data.h"
#include "enums.hpp"
#include "workplace.hpp"
#include "screening_room.h"
#include "customer.h"


class Cinema {
	private:
		// class fields
		std::string name;
		unsigned short openingHour;
		unsigned short closingHour;
		unsigned customerNum;

		Register employees;
		std::vector<ScreeningRoom> screeningRooms;

		std::vector<Workplace> otherWorkplaces;
		std::vector<Workplace> ticketCounters;
		std::vector<Workplace> foodCounters;
		std::vector<Workplace> janitorClosets;

		std::vector<Customer> customers;

		// private methods
		std::vector<Workplace>::iterator findWorkplace(unsigned ID, WorkplaceType type);
		std::vector<Workplace>* getWorkplaceVec(WorkplaceType type);
		std::vector<Customer>::iterator findCustomer(unsigned ID);
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

		unsigned getCustomerNum();
		void setCustomerNum(unsigned newValue);

		// collection manipulation
		void addEmployee(std::string name, employeeType type, unsigned short hours);
		void addEmployeesFromFile(std::string path);

		void addTicketCounter();
		void addFoodCounter();
		void addJanitorCloset();
		void addWorkplacesFromFile(std::string path);

		void addRandomCustomer(std::string moviePath);
		
		bool isWorkplace(unsigned ID, WorkplaceType type);
		bool hasEmployee(unsigned ID, WorkplaceType type);
		bool isCustomer(unsigned ID);

		// simulation related methods
		void prepareWorkplacesDay(Weekday day);
		void prepareEmployeeSchedules();
		void addScreeningRoom(std::string newName, int newCapacity);
		void addRoomsFromFile(std::string path);
		void setScheduleForWeek(std::string path);
		void printSchedule();

		bool findShowings(std::string movieName, unsigned int howManyTickets, Time time);
		std::vector<std::string> getNamesOfMovies(Time time);
		void buyTickets(std::string roomName, std::string movieName, Weekday day, unsigned int hour, unsigned int numberOfTickets);

		void addAvailabilityForAll(Weekday day);
		void addAvailabilityFor(std::string name, Weekday day);
		bool checkWorking(std::vector<std::string> names, unsigned hour, Weekday day);
		std::string updateWorkingCounters(unsigned hour, Weekday day);

		bool isWorking(WorkplaceType type, unsigned ID);
		std::string sellTickets(Time time);
		std::string movieLogs(Time time);
		
		void closeCinema();
		void openCinema();
};
