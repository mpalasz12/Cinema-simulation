#pragma once
#include <string>
#include <vector>
#include <ostream>
#include "schedule.hpp"

class Worker {
	//unspecified worker class
	//represents all types of workers without a specific assignment
	
	protected:
		//employee name
		std::string name;

		//employee type
		employeeType type;

		//hourly wage
		unsigned wage;

		//weekly salary
		unsigned salary;

		//hours in schedule this week
		unsigned short hours;

		//schedule for current week
		Schedule schedule;

		bool assembledSchedule;

		//availability for next week
		std::vector<Weekday> availability;

		//iterator returning methods
		std::vector<Weekday>::iterator findAvailability(Weekday day);
		
	public:

		// constructors
		Worker(std::string name, unsigned short hours);

		// getters
		std::string getName();
		unsigned getWage();
		unsigned getSalary();
		unsigned getHours();
		bool hasSchedule();
		employeeType getType();

		//setters
		void setName(std::string newName);
		void setWage(unsigned value);
		void setHours(unsigned short value);

		//collections
		bool isAvailable(Weekday day);
		void addAvailability(Weekday day);
		void removeAvailability(Weekday day);

		//other
		bool isWorking(Weekday day, unsigned hour);
		void salaryWithoutBonus(unsigned timeWorked);
		virtual void calculateSalary(unsigned bonus);
		virtual void assembleSchedule(unsigned time);
	 	virtual unsigned calculateBonus(unsigned performance);

		friend std::ostream& operator<<(std::ostream& os, Worker worker);
};


class TicketSeller : public Worker {
	public:
		TicketSeller(std::string name, unsigned short hours);
		void calculateSalary(unsigned bonus);
		void assembleSchedule(unsigned time);
		unsigned calculateBonus(unsigned performance);
};


class FoodSeller : public Worker {
	public:
		FoodSeller(std::string name, unsigned short hours);
		void calculateSalary(unsigned bonus);
		void assembleSchedule(unsigned time);
		unsigned calculateBonus(unsigned performance);
};

class Janitor : public Worker {
	public:
		Janitor(std::string name, unsigned short hours);
		void calculateSalary(unsigned bonus);
		void assembleSchedule(unsigned time);
		unsigned calculateBonus(unsigned performance);
};

