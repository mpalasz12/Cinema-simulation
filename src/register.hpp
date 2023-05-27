#pragma once
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "worker.hpp"
#include "enums.hpp"

class WorkerNotFoundException : public std::invalid_argument {
	public:
		WorkerNotFoundException(std::string name);
};

class Register {
	private:
		std::vector<std::unique_ptr<Worker>> workers;
		std::vector<std::unique_ptr<Worker>>::iterator findWorker(std::string name);

	public:
		Register();
		void addWorker(std::string name, unsigned short hours);
		void addTicketSeller(std::string name, unsigned short hours, unsigned short cashID);
		void addFoodSeller(std::string name, unsigned short hours);
		void addJanitor(std::string name, unsigned short hours);

		Worker findWorkerByName(std::string name);
		unsigned calculateTotalSalary();

		bool isWorker(std::string name);
		std::string workersString();

		void addAvailabilityFor(std::string name, Weekday day);
		void addAvailabilityForAll(Weekday day);
		void removeAvailabilityFor(std::string name, Weekday day);
		void removeAvailabilityForAll(Weekday day);

		void assembleScheduleForAll(unsigned openingTime, unsigned closingTime);

		unsigned calculateBonusFor(std::string name, unsigned performance);
		void calculateSalaryFor(std::string name, unsigned bonus);

		std::vector<std::string> getWorkerNamesByType(employeeType type);
		std::vector<std::string> getWorkerByTypeAndAvailability(employeeType type, Weekday day);

		friend std::ostream& operator<<(std::ostream& os, Register& reg);
};
