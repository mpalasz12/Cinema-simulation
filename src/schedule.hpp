#pragma once
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include "day.hpp"
#include "enums.hpp"


class Schedule {
	private:
		unsigned short weekNum;
		unsigned short weekHours;
		std::map<Weekday, Day> schedule;
		std::vector<Weekday> holidays;
		bool scheduleAssembled;

	public:
		//constructors
		Schedule(unsigned short num, unsigned short hours);
		Schedule(unsigned short weekNum);
		Schedule();

		//getters and setters
		unsigned short getWeekNum();
		unsigned short getWeekHours();
		void setWeekNum(unsigned short value);
		void setWeekHours(unsigned short value);

		//map
		Day getDay(Weekday day);

		//schedule assembly
		void assembleWithHours(
				std::vector<Weekday> availability, 
				unsigned short endTime
			);

		void assembleSchedule(
				unsigned short hours, 
				std::vector<Weekday> availability, 
				unsigned short startTime, 
				unsigned short endTime
			);

		//morning shifts, start around cinema opening
		void assembleScheduleMorning(
				unsigned short hours,
				std::vector<Weekday> availability,
				unsigned short startTime
			);

		//evening shifts, usually end around cinema's closure
		void assembleScheduleEvening(
				unsigned short hours,
				std::vector<Weekday> availability,
				unsigned short endTime
			);

		Day assembleDay(
				Weekday day, 
				unsigned short startTime, 
				unsigned short endTime
			);

		//other
		bool isWorkingTime(unsigned short hour);

		//TODO: implement smart schedules (long-term/project)
		void smartSchedule(unsigned short hours);
};

