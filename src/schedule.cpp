#include <iostream>
#include <vector>
#include <algorithm>
#include "schedule.hpp"
#include "enums.hpp"
#include "day.hpp"
#include <map>


Schedule::Schedule(unsigned short num, unsigned short hours):
	weekNum(num), weekHours(hours) {
	scheduleAssembled = false;
}

Schedule::Schedule(unsigned short weekNum): weekNum(weekNum) {
	scheduleAssembled = false;
	weekHours = 0;
}

Schedule::Schedule() {
	weekNum = 0;
	scheduleAssembled = false;
	weekHours = 0;
}

unsigned short Schedule::getWeekNum() {
	return weekNum;
}

void Schedule::setWeekNum(unsigned short value) {
	weekNum = value;
}

unsigned short Schedule::getWeekHours() {
	return weekHours;
}

void Schedule::setWeekHours(unsigned short value) {
	if (value <= 70) {
		weekHours = value;
	}
}

Day Schedule::getDay(Weekday day) {
	return schedule[day];
}

void Schedule::assembleSchedule(unsigned short hours, std::vector<Weekday> availability, unsigned short startTime, unsigned short endTime){

		for (auto & day : availability) {
		Day dailySchedule = assembleDay(day, startTime, endTime);
		// TODO: replace endTime - dailyHours with startTime
		schedule[day] = dailySchedule;
	}
}

void Schedule::assembleScheduleEvening(unsigned short hours, std::vector<Weekday> availability, unsigned short endTime) {
	if (endTime > 23) {
		endTime = 23;
	}
	unsigned short daysAvailable = availability.size();
	unsigned short dailyHours = hours / daysAvailable;
	unsigned short startTime = endTime - dailyHours;
	assembleSchedule(hours, availability, startTime, endTime);
}

void Schedule::assembleScheduleMorning(unsigned short hours, std::vector<Weekday> availability, unsigned short startTime) {
	if (startTime > 22) {
		startTime = 22;
	}
	unsigned short daysAvailable = availability.size();
	unsigned short dailyHours = hours / daysAvailable;
	unsigned short endTime = startTime + dailyHours;
	if (endTime > 23) {
		endTime = 23;
	}
	assembleSchedule(hours, availability, startTime, endTime);
}

void Schedule::assembleWithHours(std::vector<Weekday> availability, unsigned short endTime) {
	assembleScheduleEvening(weekHours, availability, endTime);
}

Day Schedule::assembleDay(Weekday day, unsigned short startTime, unsigned short endTime) {
	return Day(startTime, endTime);
}

