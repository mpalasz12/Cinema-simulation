#pragma once
#include <string>
#include <vector>
#include "worker.hpp"
#include "enums.hpp"
#include "customer.h"

class Workplace {
	private:
		unsigned identifier;
		WorkplaceType type;
		std::vector<std::string> assignedEmployees;
		std::vector<std::string>::iterator findEmployee(std::string name);
		std::vector<Customer*> queue;
		bool working;

	public:
		Workplace(unsigned id, WorkplaceType type);

		unsigned getIdentifier();
		void setIdentifier(unsigned value);

		WorkplaceType getType();
		void setType();

		bool isWorking();
		void setWorking(bool value);
		void addToQueue(Customer* client);
		void removeFirstFromQueue();

		bool isAssigned(std::string name);
		
		bool assignEmployee(std::string name);
		bool unassignEmployee(std::string name);

		unsigned assignedNum();
		
		std::vector<std::string> getAssignedEmployees();
};
