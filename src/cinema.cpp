#include <iostream>
#include "cinema.hpp"

Cinema::Cinema(std::string name) : name(name) {
}

std::string Cinema::getName() {
	return name;
}

void Cinema::setName(std::string newName) {
	name = newName;
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

Register Cinema::getRegister() {
	return getRegister();
}
