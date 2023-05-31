#include <iostream>
#include "simulation.hpp"
#include "enums.hpp"
#include "random_movies.h"

Simulation::Simulation(std::string cinemaName, unsigned short opening, unsigned short closing) : cinema(cinemaName, opening, closing), currentStep(0), time(Weekday::Monday, opening) {
	
}
unsigned Simulation::getCurrentStep() {
	return currentStep;
}

void Simulation::setCurrentStep(unsigned int value) {
	currentStep = value;
}

void Simulation::increaseStep() {
	currentStep++;
}

std::string Simulation::getMoviePath() {
	return moviePath;
}

void Simulation::setMoviePath(std::string path) {
	moviePath = path;
}

void Simulation::startSimulation() {
	prepareWeek();
	prepareDay();
	return;
}

void Simulation::addToLog(std::string log) {
	simLog.addToStepLog(log);
}

std::string Simulation::getStepLog() {
	return simLog.getStepLog();
}

void Simulation::prepareWeek() {
	// tu mają sie wywoływać metody z cinema tworzące plany tygodniowe
	cinema.prepareEmployeeSchedules();
	cinema.setScheduleForWeek(moviePath);
}

void Simulation::prepareDay() {
	cinema.prepareWorkplacesDay(time.getDay());
}

void Simulation::runStep() {
	// tu cogodzinne zmiany

	addToLog(cinema.updateWorkingCounters(time.getHour(), time.getDay()));

	// get random amount of customers in range (10, 60)
	unsigned newCustomers = generateRandomNumber(10, 60);
	std::string log;
	log.append(std::to_string(newCustomers));
	log.append(" new customers arrived at the cinema this hour");
	addToLog(log);

	for (unsigned i; i <= newCustomers; i++) {
		// create the employees and get them in a random queue
		cinema.addRandomCustomer(moviePath);

		time.increaseHour();
	}

	// sell tickets and add the information to the log
	addToLog(cinema.sellTickets());

}

