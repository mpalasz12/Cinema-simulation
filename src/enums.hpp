#pragma once
#include <initializer_list>

enum class Weekday {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday,
};

constexpr std::initializer_list<Weekday> weekdays = {
	Weekday::Monday,
	Weekday::Tuesday,
	Weekday::Wednesday,
	Weekday::Thursday,
	Weekday::Friday,
	Weekday::Saturday,
	Weekday::Sunday};


enum class employeeType {
	worker,
	ticketSeller,
	foodSeller,
	janitor,
};

enum class WorkplaceType {
	ticketCounter,
	janitorialCloset,
	foodCounter,
};
