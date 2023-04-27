#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "day.hpp"

InvalidHourException::InvalidHourException(unsigned short wrongTime):
	std::invalid_argument("Hour needs to be in (0, 24) range: " + std::to_string(wrongTime))
{}

Day::Day() {
	working = false;
}

Day::Day(unsigned short start, unsigned short end) {
	working = true;
	if (validTime(start)) {
		startTime = start;
	} else {
		throw(InvalidHourException(startTime));
	}

	if (validTime(end) && greaterThanStart(end)) {
		endTime = end;
	} else {
		throw(InvalidHourException(endTime));
	}
}

unsigned short Day::getStartTime() {
	return startTime;
}

unsigned short Day::getEndTime() {
	return endTime;
}

bool Day::isWorking() {
	return working;
}

bool Day::setStartTime(unsigned short time) {
	if (validTime(time) && (time < endTime)) {
		startTime = time;
		return true;
	} else {
		return false;
	}
}

bool Day::setEndTime(unsigned short time) {
	if (validTime(time) && greaterThanStart(time)) {
		endTime = time;
		return true;
	} else {
		return false;
	}
}

bool Day::validTime(unsigned short time) {
	return (time < 24);
}

bool Day::greaterThanStart(unsigned short time) {
	return (time > startTime);
}

// methods for assembling smart schedules (for the project)

bool Day::isWorkingTime(unsigned short hour) {
	return ((hour >= startTime) && (hour <= endTime));
}

bool Day::workOverlap(unsigned short start, unsigned short end) {
	if (start < startTime) {
		return !(end < startTime);
	} else {
		return !(start > endTime);
	}
}
