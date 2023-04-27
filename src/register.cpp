#include "register.hpp"
#include "worker.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <algorithm>
#include <numeric>

WorkerNotFoundException::WorkerNotFoundException(std::string name) :
	std::invalid_argument("Unable to find worker with given name " + name)
{}

Register::Register()
{}

void Register::addWorker(std::string name, unsigned short hours) {
	std::unique_ptr<Worker> worker = std::make_unique<Worker>(name, hours);
	workers.push_back(std::move(worker));
}

void Register::addTicketSeller(std::string name, unsigned short hours, unsigned short cashID) {
	std::unique_ptr<TicketSeller> worker = std::make_unique<TicketSeller>(name, hours, cashID);
	workers.push_back(std::move(worker));
}

void Register::addFoodSeller(std::string name, unsigned short hours) {
	std::unique_ptr<FoodSeller> worker = std::make_unique<FoodSeller>(name, hours);
	workers.push_back(std::move(worker));
}

void Register::addJanitor(std::string name, unsigned short hours) {
	std::unique_ptr<Janitor> worker = std::make_unique<Janitor>(name, hours);
	workers.push_back(std::move(worker));
}


std::vector<std::unique_ptr<Worker>>::iterator Register::findWorker(std::string name) {
	auto result = std::find_if(workers.begin(), workers.end(),
		[&name](std::unique_ptr<Worker>& worker) {
			return (worker -> getName() == name);
		});
	return result;
}

Worker Register::findWorkerByName(std::string name) {
	auto result = findWorker(name);
	if (result != workers.end()) {
		return **result;
	} else {
		throw(WorkerNotFoundException(name));
	}
}

unsigned Register::calculateTotalSalary() {
	unsigned sum = std::accumulate(workers.begin(), workers.end(), 0,
		[](unsigned total, std::unique_ptr<Worker>& worker) {
			if ((worker -> getSalary()) == 0) {
				worker -> calculateSalary(0);
			}
			total += (worker -> getSalary());
			return total;
		});

	return sum;
}

void Register::addAvailabilityFor(std::string name, Weekday day) {
	auto result = findWorker(name);
	if (result != workers.end()) {
		std::unique_ptr<Worker>& worker = *result;
		worker -> addAvailability(day);
	}
}

void Register::removeAvailabilityFor(std::string name, Weekday day) {
	auto result = findWorker(name);
	if (result != workers.end()) {
		std::unique_ptr<Worker>& worker = *result;
		worker -> removeAvailability(day);
	}
}

void Register::addAvailabilityForAll(Weekday day) {
	for (auto& worker : workers) {
		worker -> addAvailability(day);
	}
}

void Register::removeAvailabilityForAll(Weekday day) {
	for (auto& worker : workers) {
		worker -> removeAvailability(day);
	}
}

void Register::calculateSalaryFor(std::string name, unsigned bonus) {
	auto result = findWorker(name);
	if (result != workers.end()) {
		std::unique_ptr<Worker>& worker = *result;
		worker -> calculateSalary(bonus);
	}
}

unsigned Register::calculateBonusFor(std::string name, unsigned performance) {
	auto result = findWorker(name);
	if (result != workers.end()) {
		std::unique_ptr<Worker>& worker = *result;
		unsigned bonus = worker -> calculateBonus(performance);
		return bonus;
	} else {
		throw(WorkerNotFoundException(name));
	}
}

std::string Register::workersString() {
	unsigned index = 1;
	std::stringstream ss;
	for (auto& worker : workers) {
		ss << index << ". " << *worker;
		index++;
	}
	return ss.str();
}

std::ostream& operator <<(std::ostream& os, Register& reg) {
	os << reg.workersString();
	return os;
}
