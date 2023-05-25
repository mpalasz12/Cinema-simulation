#pragma once
#include <string>
#include <vector>
#include <memory>
#include "cinema.hpp"
#include "register.hpp"
#include "schedule.hpp"
#include "simlog.hpp"

// tego jeszcze nie robie bo by wypadalo zeby byly wszystkie klasy zwiazane z kinem

class Simulation {
	private:
		Cinema cinema;
		unsigned currentStep;
		SimLog simLog;
		std::vector<std::string>::iterator findLog;
		unsigned short time;
	public:
		Simulation(Cinema cinema);

		unsigned getCurrentStep();
		void setCurrentStep(unsigned value);
		void increaseStep();

		void startSimulation();
		void runStep();

		void prepareWeek();

		void addToLog(std::string log);
		std::string getStepLog();
};
