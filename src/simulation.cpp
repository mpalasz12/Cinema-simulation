#include <iostream>
#include "simulation.hpp"
#include "enums.hpp"

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

void Simulation::startSimulation() {
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
	cinema.setScheduleForWeek();
}

void Simulation::prepareDay() {
	cinema.prepareWorkplacesDay(time.getDay());
}
