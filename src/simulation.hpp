#pragma once
#include <string>
#include <memory>
#include "cinema.hpp"
#include "register.hpp"
#include "schedule.hpp"
#include "simlog.hpp"
#include "time.h"

class Simulation {
	private:
		Cinema cinema;
		unsigned currentStep;
		SimLog simLog;
		Time time;
		std::string moviePath;
	public:
		Simulation(std::string cinemaName, unsigned short opening, unsigned short closing);

		unsigned getCurrentStep();
		void setCurrentStep(unsigned value);
		void increaseStep();

		std::string getMoviePath();
		void setMoviePath(std::string path);

		void startSimulation();
		void runStep();

		void prepareWeek();
		void prepareDay();

		void addToLog(std::string log);
		std::string getStepLog();

		void stepCounters();
		void stepMovieRooms();
};
