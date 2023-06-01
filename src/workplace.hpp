#pragma once
#include <string>
#include <vector>
#include <deque>
#include "worker.hpp"
#include "enums.hpp"
#include "customer.h"

class Workplace {
	private:
		unsigned identifier;
		WorkplaceType type;
		std::vector<std::string> assignedEmployees;
		std::vector<std::string>::iterator findEmployee(std::string name);
		std::deque<unsigned> queue;
		bool working;

	public:
		Workplace(unsigned id, WorkplaceType type);

		unsigned getIdentifier();
		void setIdentifier(unsigned value);

		WorkplaceType getType();
		void setType();

		bool isWorking();
		void setWorking(bool value);
		void addToQueue(unsigned client);
		void removeFirstFromQueue();

		bool isAssigned(std::string name);
		
		bool assignEmployee(std::string name);
		bool unassignEmployee(std::string name);

		unsigned assignedNum();

		unsigned getQueueSize();
		unsigned getFirstCustomer();

		std::vector<std::string> getAssignedEmployees();

		void clearAssigned();

		void sell();
		void closeCounter();
};
