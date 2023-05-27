#include <iostream>
#include <algorithm>
#include "workplace.hpp"

Workplace::Workplace(unsigned id, WorkplaceType type) :
	identifier(id), type(type) {

}

unsigned Workplace::getIdentifier() {
	return identifier;
}

void Workplace::setIdentifier(unsigned value) {
	identifier = value;
}

std::vector<std::string>::iterator Workplace::findEmployee(std::string name) {
	auto result = std::find(assignedEmployees.begin(), assignedEmployees.end(), name);
	return result;
}

bool Workplace::isAssigned(std::string name) {
	auto result = findEmployee(name);
	
	return (result != assignedEmployees.end());
}

bool Workplace::assignEmployee(std::string name) {
	if (!isAssigned(name)) {
		assignedEmployees.push_back(name);
		return true;
	} else {
		return false;
	}
}

bool Workplace::unassignEmployee(std::string name) {
	auto result = findEmployee(name);
	if (result != assignedEmployees.end()) {
		assignedEmployees.erase(result);
		return true;
	} else {
		return false;
	}
}
