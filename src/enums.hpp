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

enum class employeeType {
	worker,
	ticketSeller,
	foodSeller,
	janitor,
};

constexpr std::initializer_list<employeeType> types = {
	employeeType::worker,
	employeeType::ticketSeller,
	employeeType::foodSeller,
	employeeType::janitor,
};

enum class WorkplaceType {
	ticketCounter,
	janitorialCloset,
	foodCounter,
};
