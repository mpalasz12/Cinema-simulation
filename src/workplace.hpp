#pragma once
#include <string>
#include <vector>
#include "worker.hpp"
#include "enums.hpp"

class Workplace {
	private:
		unsigned identifier;
		WorkplaceType type;
		std::vector<std::string> assignedEmployees;
		std::vector<std::string>::iterator findEmployee(std::string name);
		bool working;

	public:
		Workplace(unsigned id, WorkplaceType type);

		unsigned getIdentifier();
		void setIdentifier(unsigned value);

		WorkplaceType getType();
		void setType();

		bool isWorking();
		void setWorking(bool value);

		bool isAssigned(std::string name);
		
		bool assignEmployee(std::string name);
		bool unassignEmployee(std::string name);

		unsigned assignedNum();
		
		std::vector<std::string> getAssignedEmployees();
};
