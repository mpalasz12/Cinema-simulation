#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <stdexcept>

class InvalidHourException : public std::invalid_argument {
	public:
		InvalidHourException(unsigned short wrongTime);
};

class Day {
	private:
		bool working;
		unsigned short startTime;
		unsigned short endTime;
		bool validTime(unsigned short time);
		bool greaterThanStart(unsigned short time);
	public:
		// constructors
		Day(unsigned short start, unsigned short end);
		Day();
		
		// getters
		unsigned short getStartTime();
		unsigned short getEndTime();
		bool isWorking();
		bool isWorkingTime(unsigned short hour);
		bool workOverlap(unsigned short start, unsigned short end);

		//setters
		bool setStartTime(unsigned short time);
		bool setEndTime(unsigned short time);
};
