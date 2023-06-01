#include <iostream>
#include "simulation.hpp"
#include "enums.hpp"
#include "random_movies.h"
#include "read_from_file.h"

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
std::string Simulation::getRoomsPath()
{
	return roomsPath;
}
void Simulation::setRoomsPath(std::string newPath)
{
	roomsPath = newPath;
}
std::string Simulation::getMoviePath() {
	return moviePath;
}

void Simulation::setMoviePath(std::string path) {
	moviePath = path;
}

std::string Simulation::getEmployeePath() {
	return employeePath;
}

void Simulation::setEmployeePath(std::string path) {
	employeePath = path;
}

void Simulation::readEmployeesFromFile() {
	cinema.addEmployeesFromFile(employeePath);
}

std::string Simulation::getWorkplacePath() {
	return workplacePath;
}

void Simulation::setWorkplacePath(std::string path) {
	workplacePath = path;
}

void Simulation::readWorkplacesFromFile() {
	cinema.addWorkplacesFromFile(workplacePath);
}

void Simulation::startSimulation() {
	cinema.addRoomsFromFile(roomsPath);
	readWorkplacesFromFile();
	readEmployeesFromFile();
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

std::string Simulation::runStep() {
	// tu cogodzinne zmiany
	
	std::string msg = "---------- ";
	msg.append(time.timeToString());
	msg.append(" ----------");
	addToLog(msg);

	addToLog(cinema.updateWorkingCounters(time.getHour(), time.getDay()));

	std::string log;

	if (cinema.areMoreFilms(time)) {
		// get random amount of customers in range (10, 60)
		unsigned newCustomers = generateRandomNumber(10, 30);
		std::string log;
		log.append(std::to_string(newCustomers));
		log.append(" new customers arrived at the cinema this hour");
		addToLog(log);

		std::vector<std::string> movies = cinema.getNamesOfMovies(time);

		for (unsigned i = 0; i <= newCustomers; i++) {
			// create the employees and get them in a random queue
			cinema.addRandomCustomer(movies);

		}
	}

	// sell tickets and add the information to the log
	addToLog(cinema.sellTickets(time));
	addToLog(cinema.movieLogs(time));
	log = getStepLog();
	simLog.clearStepLog();
	if (!closeCinemaIfNeeded()) {
		time.increaseHour();
	}
	return log;


}

bool Simulation::closeCinemaIfNeeded() {
	if (time.getHour() == cinema.getClosingHour()) {
		cinema.closeCinema();
		addToLog("Cinema closed for the day.");
		time.setHour(cinema.getOpeningHour());
		int currentDay = static_cast<int>(time.getDay());
		if (currentDay == 6) {
			currentDay = 0;
		} else {
			currentDay++;
		}
		Weekday newDay{currentDay};
		time.setDay(newDay);
		if (time.getDay() == Weekday::Monday) {
			prepareWeek();
		}
		prepareDay();
		return true;
	} else {
		return false;
	}
}


