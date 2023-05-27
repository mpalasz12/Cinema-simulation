#include <iostream>
#include <algorithm>
#include "cinema.hpp"
#include"screening_room.h"
#include "workplace.hpp"

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



void Cinema::addEmployee(std::string name, employeeType type, unsigned short hours) {
	switch(type) {
		case employeeType::worker:
			employees.addWorker(name, hours);
			break;
		case employeeType::ticketSeller:
			employees.addTicketSeller(name, hours, 0);
			break;
		case employeeType::foodSeller:
			employees.addFoodSeller(name, hours);
			break;
		case employeeType::janitor:
			employees.addJanitor(name, hours);
			break;
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

std::vector<Workplace>::iterator Cinema::findWorkplace(unsigned ID, WorkplaceType type) {

	auto workplaceVec = getWorkplaceVec(type);

	auto result = find_if(workplaceVec.begin(), workplaceVec.end(), 
			[ID](auto workplace) {
				return workplace.getIdentifier() == ID;
			});

	return result;
}

std::vector<Workplace>& Cinema::getWorkplaceVec(WorkplaceType type) {
	std::vector<Workplace>& workplaceVec = ticketCounters;
	switch (type) {
		case WorkplaceType::ticketCounter:
			break;
		case WorkplaceType::foodCounter:
			workplaceVec = foodCounters;
			break;
		case WorkplaceType::janitorialCloset:
			workplaceVec = janitorClosets;
			break;
		case WorkplaceType::other:
			workplaceVec = otherWorkplaces;
			break;
	}
	return workplaceVec;
}

bool Cinema::isWorkplace(unsigned ID, WorkplaceType type) {
	auto workplaceVec = getWorkplaceVec(type);
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
void Cinema::setScheduleForWeek()
{
	for (ScreeningRoom& room : screeningRooms) 
	{
		room.fillSchedule();
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
void Cinema::buyTickets(std::string roomName, std::string movieName, Weekday day, int hour, int numberOfTickets)
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
                        std::cout << "Bought" << std::endl;
                        return;
                    }
                    else
                    {
                        std::cout << "Not enough free chairs" << std::endl;
                        return;
                    }
                }
            }
            std::cout << "Movie not found" << std::endl;
			break;
        }
    }

    std::cout << "Room with such name not found " << std::endl;
}


void Cinema::addAvailabilityForAll(Weekday day) {
	employees.addAvailabilityForAll(day);
}
