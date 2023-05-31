#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include "cinema.hpp"
#include"screening_room.h"
#include "workplace.hpp"
#include "random_movies.h"
#include "read_from_file.h"

Cinema::Cinema(std::string name, unsigned short opening, unsigned short closing) :
	name(name), openingHour(opening), closingHour(closing) {
}

std::string Cinema::getName() {
	return name;
}

void Cinema::setName(std::string newName) {
	name = newName;
}

unsigned short Cinema::getOpeningHour() {
	return openingHour;
}

unsigned short Cinema::getClosingHour() {
	return closingHour;
}

void Cinema::setOpeningHour(unsigned short hour) {
	openingHour = hour;
}

void Cinema::setClosingHour(unsigned short hour) {
	closingHour = hour;
}

unsigned Cinema::getCustomerNum() {
	return customerNum;
}

void Cinema::setCustomerNum(unsigned int newValue) {
	customerNum = newValue;
}



void Cinema::addEmployee(std::string name, employeeType type, unsigned short hours) {
	switch(type) {
		case employeeType::worker:
			employees.addWorker(name, hours);
			break;
		case employeeType::ticketSeller:
			employees.addTicketSeller(name, hours);
			break;
		case employeeType::foodSeller:
			employees.addFoodSeller(name, hours);
			break;
		case employeeType::janitor:
			employees.addJanitor(name, hours);
			break;
	}
}
void Cinema::addEmployeesFromFile(std::string path)
{
    std::ifstream file(path);
    if (file.is_open()) 
    {
        std::string line;
        std::string field;
        std::string name;
        unsigned hours;
        employeeType type;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::getline(iss, field, ',');
            name = field;

            std::getline(iss, field, ',');
            hours = std::stoul(field);

            std::getline(iss, field, ',');
            type = convertToEmployeeType(field);

			addEmployee(name, type, hours);

			for(int i=0; i<7; i++)
			{
				std::getline(iss, field, ',');
				if(field == "1")
				{
					addAvailabilityFor(name, convertToWeekdayType(i));
				}
			}
        }
        file.close();
    }
    else {
        std::cout << "Can't open a file." << std::endl;
    }
}
void Cinema::addTicketCounter() {
	Workplace counter(ticketCounters.size(), WorkplaceType::ticketCounter);
	ticketCounters.push_back(counter);
}

void Cinema::addFoodCounter() {
	Workplace counter(foodCounters.size(), WorkplaceType::foodCounter);
	foodCounters.push_back(counter);
}

void Cinema::addJanitorCloset() {
	Workplace closet(janitorClosets.size(), WorkplaceType::janitorialCloset);
	janitorClosets.push_back(closet);
}
void Cinema::addWorkplacesFromFile(std::string path)
{
	std::ifstream file(path);
    if (file.is_open()) 
    {
        std::string line;
        std::string field;
        unsigned howMany;
        WorkplaceType workplaceType;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::getline(iss, field, ',');
			workplaceType = convertToWorkplaceType(field);
			std::getline(iss, field, ',');
			howMany = std::stoul(field);

			switch (workplaceType)
			{
			case WorkplaceType::ticketCounter:
				for(unsigned i=0; i<howMany; i++)
				{
					addTicketCounter();
				}
				break;
			case WorkplaceType::foodCounter:
				for(unsigned i=0; i<howMany; i++)
				{
					addFoodCounter();
				}
				break;
				case WorkplaceType::janitorialCloset:
				for(unsigned i=0; i<howMany; i++)
				{
					addJanitorCloset();
				}
				break;
				case WorkplaceType::other:
				break;
			}
        }
        file.close();
    }
    else {
        std::cout << "Can't open a file." << std::endl;
    }
}
std::vector<Workplace>::iterator Cinema::findWorkplace(unsigned ID, WorkplaceType type) {

	auto workplaceVec = *getWorkplaceVec(type);

	auto result = find_if(workplaceVec.begin(), workplaceVec.end(), 
			[ID](auto workplace) {
				return workplace.getIdentifier() == ID;
			});

	return result;
}

std::vector<Workplace>* Cinema::getWorkplaceVec(WorkplaceType type) {
	std::vector<Workplace>* workplaceVec = nullptr;
	switch (type) {
		case WorkplaceType::ticketCounter:
			workplaceVec = &ticketCounters;
			break;
		case WorkplaceType::foodCounter:
			workplaceVec = &foodCounters;
			break;
		case WorkplaceType::janitorialCloset:
			workplaceVec = &janitorClosets;
			break;
		case WorkplaceType::other:
			workplaceVec = &otherWorkplaces;
			break;
	}
	return workplaceVec;
}

std::vector<Customer>::iterator Cinema::findCustomer(unsigned ID) {
	auto result = std::find_if(customers.begin(), customers.end(),
			[ID](auto& customer) {
				return customer.getID() == ID;
			});
	return result;
}

bool Cinema::isWorkplace(unsigned ID, WorkplaceType type) {
	auto workplaceVec = *getWorkplaceVec(type);
	auto result = findWorkplace(ID, type);
	return (result != workplaceVec.end());
}

bool Cinema::hasEmployee(unsigned ID, WorkplaceType type) {
	if (isWorkplace(ID, type)) {
		auto result = findWorkplace(ID, type);
		return result -> assignedNum() != 0;
	} else {
		return false;
	}

}

bool Cinema::isCustomer(unsigned ID) {
	auto result = findCustomer(ID);
	return result != customers.end();
}

void Cinema::prepareWorkplacesDay(Weekday day) {
	// set schedules and assign employees to counters
	std::vector<std::string> availability;
	std::vector<std::string>::iterator avalIterator;
	std::vector<Workplace>* workplaceType = nullptr;

	// Iterate for each worker type
	for (auto type : types) {
		// get workplace objects
		switch(type) {
			case employeeType::worker:
				workplaceType = &otherWorkplaces;
				break;
			case employeeType::ticketSeller:
				workplaceType = &ticketCounters;
				break;
			case employeeType::foodSeller:
				workplaceType = &foodCounters;
				break;
			case employeeType::janitor:
				workplaceType = &janitorClosets;
				break;
		}

			availability = employees.getWorkerByTypeAndAvailability(type, day);
			avalIterator = availability.begin();

			// assign them to all available counters
			// if employees > counters, more than one employee may be assigned to a workplace
			for (auto& counter : *workplaceType) {
				if (avalIterator == availability.end()) {
					break;
				}
				if (std::distance(availability.begin(), avalIterator) - workplaceType -> size() >= 0) {
					
					counter.assignEmployee(*avalIterator);
					avalIterator++;
				} else {
					avalIterator = availability.begin();
				}
			}
		}
	}

void Cinema::prepareEmployeeSchedules() {
	employees.assembleScheduleForAll(openingHour, closingHour);
}
void Cinema::addScreeningRoom(std::string newName, int newCapacity)
{
	ScreeningRoom screeningRoom(newName, newCapacity);
	screeningRooms.push_back(screeningRoom);
}
void Cinema::addRoomsFromFile(std::string path)
{
    std::ifstream file(path);
    if (file.is_open()) 
    {
        std::string line;
        std::string field;

        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::getline(iss, field, ',');
            std::string screeningRoomName = field;

            std::getline(iss, field, ',');
            unsigned short capacity = std::stoul(field);
            addScreeningRoom(screeningRoomName, capacity);
        }

        file.close();
    }
    else {
        std::cout << "Can't open a file." << std::endl;
    }
}
void Cinema::setScheduleForWeek(std::string path)
{
	for (ScreeningRoom& room : screeningRooms) 
	{
		room.fillSchedule(openingHour, closingHour, path);
    }
}
void Cinema::printSchedule()
{
    for (ScreeningRoom& room : screeningRooms) 
	{
        std::cout << room.getName() << ": ";
		room.printSchedule();
    }
}
bool Cinema::findShowings(std::string movieName, unsigned howManyTickets, Time time)
{
	for (ScreeningRoom& room : screeningRooms)
	{
		for(int x=0; x<7; x++)
		{
			std::vector<Showing>& schedule = room.getSchedule(static_cast<int>(x));
			for (Showing& showing : schedule)
        {
            if (showing.getName() == movieName)
            {
				if(time.getDay() >= showing.getDay())
				{
					if(time.getHour() >= showing.getHour())
					{
						if (showing.getFreeChairs() >= howManyTickets)
						{
							buyTickets(room.getName(), showing.getName(), showing.getDay(), showing.getHour(), howManyTickets);
							return true;
						}
					}
				}

            }
        }
		}
	}
	return false;
}
void Cinema::buyTickets(std::string roomName, std::string movieName, Weekday day, unsigned int hour, unsigned int numberOfTickets)
{
    for (ScreeningRoom& room : screeningRooms) 
    {
        if (room.getName() == roomName)
        {
            std::vector<Showing>& schedule = room.getSchedule(static_cast<int>(day));

            for (auto it = schedule.begin(); it != schedule.end(); ++it)
            {
                Showing& showing = *it;
                if (showing.getHour() == hour && showing.getName() == movieName)
                {
                    if (showing.getFreeChairs() >= numberOfTickets)
                    {
                        showing.setFreeChairs(showing.getFreeChairs() - numberOfTickets);
                        return;
                    }
                    else
                    {
                        return;
                    }
                }
            }
			return;
        }
    }

}


void Cinema::addAvailabilityForAll(Weekday day) {
	employees.addAvailabilityForAll(day);
}

bool Cinema::checkWorking(std::vector<std::string> names, unsigned hour, Weekday day) {
	for (std::string employee : names) {
		if (employees.isWorking(employee, hour, day)) {
			return true;
		}
	}
	return false;
}

std::string Cinema::updateWorkingCounters(unsigned hour, Weekday day) {
	std::string result = "";
	for (auto type : workplaceTypes) {
		auto& workplaceVec = *getWorkplaceVec(type);
		for (auto& workplace : workplaceVec) {
			auto names = workplace.getAssignedEmployees();
			if (checkWorking(names, hour, day)) {
				if (!workplace.isWorking()) {
					workplace.setWorking(true);
					if (type == WorkplaceType::ticketCounter) {
						result.append("Ticket counter (");
					} else if (type == WorkplaceType::foodCounter) {
						result.append("Food counter (");
					} else {
						result.append("Workplace (");
					}
					result.append(std::to_string(workplace.getIdentifier()));
					result.append(") started working \n");
				}
			} else {
				if (workplace.isWorking()) {
					workplace.setWorking(false);
					result.append("Ticket counter (");
					result.append(std::to_string(workplace.getIdentifier()));
					result.append(") stopped working \n");
				}
			}
		}
	}
	return result;
}

bool Cinema::isWorking(WorkplaceType type, unsigned ID) {
	auto result = findWorkplace(ID, type);
	return result -> isWorking();
}

void Cinema::addRandomCustomer(std::string moviePath) {
	unsigned age = generateRandomNumber(5, 85);
	unsigned ticketAmt = generateRandomNumber(1, 6);
	std::string movieTitle = randomMovie(moviePath).getName();

	customerNum++;

	Customer customer(customerNum, age, movieTitle, ticketAmt);
	customers.push_back(customer);

	unsigned counterNum = generateRandomNumber(0, ticketCounters.size() - 1);
	Workplace& counter = ticketCounters.at(counterNum);
	counter.addToQueue(customer.getID());
	
	// get random counter and assign the customer pointer to it
}

std::string Cinema::sellTickets(Time time) {
	std::string result = "";
	// iterate for every ticket counter
	for (auto& counter : ticketCounters) {
		// check if it's working
		if (counter.isWorking()) {

		// get a random number of customers to serve each hour
			unsigned customersToServe = generateRandomNumber(10, 25);
			unsigned servedID;
			while (customersToServe != 0 && counter.getQueueSize() != 0) {
				customersToServe--;
				servedID = counter.getFirstCustomer();
				if (isCustomer(servedID)) {
					auto customer = findCustomer(servedID);
					if (findShowings(customer -> getMovieName(), customer -> getHowManyTickets(), time)) {
						result.append("Customer (ID: ");
						result.append(std::to_string(customer -> getID()));
						result.append("), bought ");
						result.append(std::to_string(customer -> getHowManyTickets()));
						if (customer -> getAge() < 18) {
							result.append(" discounted");
						}
						result.append(" tickets for ");
						result.append(customer -> getMovieName());
						result.append("\n");
					} else {
						result.append("Customer (ID: ");
						result.append(std::to_string(customer -> getID()));
						result.append("), tried to buy ");
						result.append(std::to_string(customer -> getHowManyTickets()));
						result.append(" tickets for ");
						result.append(customer -> getMovieName());
						result.append(", but was unable to");
						result.append("\n");

					}
				}
				
				counter.removeFirstFromQueue();
			}
		}
	}
	return result;
}
std::string Cinema::movieLogs(Time time)
{
	std::string result;
	for (ScreeningRoom& room : screeningRooms)
	{
		std::vector<Showing> daySchedule = room.getSchedule(static_cast<int>(time.getDay()));
		for(Showing& showing : daySchedule)
		{
			if(showing.getHour() == time.getHour())
			{
				result.append("Movie named ");
				result.append(showing.getName());
				result.append(" started at ");
				result.append(std::to_string(time.getHour()));
				result.append(":00 ");
				switch (time.getDay()) 
				{
				case Weekday::Monday:
					result.append("on monday in room ");
					break;
				case Weekday::Tuesday:
					result.append("on tuesday in room ");
					break;
				case Weekday::Wednesday:
					result.append("on wednesday in room ");
					break;
				case Weekday::Thursday:
					result.append("on thursday in room ");
					break;
				case Weekday::Friday:
					result.append("on friday in room ");
					break;
				case Weekday::Saturday:
					result.append("on saturday in room ");
					break;
				case Weekday::Sunday:
					result.append("on sunday in room ");
					break;
				}
				result.append(room.getName());
				result.append(" with ");
				result.append(std::to_string(room.getCapacity() - showing.getFreeChairs()));
				result.append("/");
				result.append(std::to_string(room.getCapacity()));
				result.append(" people ");
				result.append("\n");
			}
		}
	}
	return result;
}

void Cinema::addAvailabilityFor(std::string name, Weekday day) {
	employees.addAvailabilityFor(name, day);
}

void Cinema::closeCinema() {
	for (auto counter : ticketCounters) {
		counter.closeCounter();
	}
	
	for (auto counter : foodCounters) {
		counter.closeCounter();
	}
}
