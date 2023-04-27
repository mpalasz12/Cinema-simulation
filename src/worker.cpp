#include <iostream>
#include <vector>
#include <algorithm>
#include "schedule.hpp"
#include "worker.hpp"

const int MIN_WAGE = 18;
const int SELLER_WAGE = 20;
const int JANITOR_WAGE = 19;

//WORKER

Worker::Worker(std::string name, unsigned short hours): name(name), hours(hours) {
	wage = MIN_WAGE;
	salary = 0;
	hours = 0;
}

unsigned Worker::getWage() {
	return wage;
}

unsigned Worker::getSalary() {
	return salary;
}

unsigned Worker::getHours() {
	return hours;
}

std::string Worker::getName() {
	return name;
}

bool Worker::hasSchedule() {
	return assembledSchedule;
}

void Worker::setName(std::string newName) {
	name = newName;
}

void Worker::setWage(unsigned value) {
	wage = value;
}

void Worker::setHours(unsigned short value) {
}

std::vector<Weekday>::iterator Worker::findAvailability(Weekday day) {
	std::vector<Weekday>::iterator result = find(availability.begin(), availability.end(), day);
	return result;
}

bool Worker::isAvailable(Weekday day) {
	auto result = findAvailability(day);

	return (result != availability.end());
}

void Worker::addAvailability(Weekday day) {
	if (!isAvailable(day)) {
		availability.push_back(day);
	}
}

void Worker::removeAvailability(Weekday day) {
	auto query = findAvailability(day);
	if (query != availability.end()) {
		availability.erase(query);
	}
}

void Worker::salaryWithoutBonus(unsigned int timeWorked) {
	salary = timeWorked * wage;
}

void Worker::calculateSalary(unsigned bonus) {
	salary = hours * wage + bonus;
}

unsigned Worker::calculateBonus(unsigned performance) {
	//performance is an indicator how well an employee did on a given week
	//for unspecified workers bonus is given for working on the weekends
	//(1 performance per weekend day worked)
	
	if (isAvailable(Weekday::Saturday) || isAvailable(Weekday::Sunday)) {
		performance += 50;
	}
	
	if (performance > 200) {
		performance = 200;
	}
	return performance;
}

void Worker::assembleSchedule(unsigned time) {

	//in this case endTime is the time at which the cinema will close
	//unspecified workers will work morning shifts, starting upon the cinema opening
	schedule.assembleScheduleMorning(hours, availability, time);
}


std::ostream& operator<<(std::ostream& os, Worker worker) {
	os << "name: " << worker.getName() << " | " << "wage: " << worker.getWage() << " | ";
	os << "salary: " << worker.getSalary() << " | " << std::endl;
	return os;
}

// -----------
// TICKET SELLER
// -----------

TicketSeller::TicketSeller(std::string name, unsigned short hours, unsigned short cashID) :
	Worker(name, hours), cashID(cashID) {
	wage = SELLER_WAGE;
	salary = 0;
}

void TicketSeller::calculateSalary(unsigned bonus) {
	float multiplier = 1;
	if (availability.size() >= 3) {
		multiplier = 1.1;
	}
	
	salary = hours * wage * multiplier + bonus;
}

unsigned TicketSeller::calculateBonus(unsigned performance) {
	
	//in case of ticket sellers, performance is the amount of tickets sold within last week
	return performance;
}

void TicketSeller::assembleSchedule(unsigned int time) {
	
	//since cinema traffic is highest in the evenings, ticket sellers will work evening shifts
	//time is expected to be the cinema's closure time in this case
	schedule.assembleScheduleEvening(hours, availability, time);
}

// -----------
// FOOD SELLER
// -----------

FoodSeller::FoodSeller(std::string name, unsigned short hours) : Worker(name, hours) {
	wage = SELLER_WAGE;
	salary = 0;
}

void FoodSeller::calculateSalary(unsigned bonus) {

	// in case of food sellers, we want to ensure that the bonus is at least 80 if the employee worked for at least two days a week
	if ((bonus < 50) && (availability.size() >= 2)) {
		bonus = 50;
	}
	salary = hours * wage + bonus;
}

unsigned FoodSeller::calculateBonus(unsigned performance) {
	
	//in case of food sellers, bonus is 1/2 of food sold multiplied by 2 if the employee worked on a weekend
	if (!isAvailable(Weekday::Saturday) && !isAvailable(Weekday::Sunday)) {
		performance = performance / 2;
	}
	return performance;
}

void FoodSeller::assembleSchedule(unsigned int time) {
	
	//since cinema traffic is highest in the evenings, food sellers will work evening shifts
	//shift end time is expected to be one hour before cinema closure
	schedule.assembleScheduleMorning(hours, availability, time - 1);
}


// -----------
// JANITOR
// -----------

Janitor::Janitor(std::string name, unsigned short hours) : Worker(name, hours)  {
	wage = JANITOR_WAGE;
	salary = 0;
}

void Janitor::calculateSalary(unsigned int bonus) {
	salary = hours * wage + bonus;
}

void Janitor::assembleSchedule(unsigned time) {
	schedule.assembleScheduleMorning(hours, availability, time -1);
}

unsigned Janitor::calculateBonus(unsigned performance) {
	// in case of janitors, bonus is based on cinema's cleanliness
	// cleanliness can range from 0 to 100 and is multiplied by 1.5 to calculate the bonus
	
	if (performance > 100) {
		performance = 100;
	}
	performance = performance * 1.5;
	return performance;
}

