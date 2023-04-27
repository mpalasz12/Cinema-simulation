#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "register.hpp"

Weekday getWeekday(std::string day) {
	std::map<std::string, Weekday> days {
		{"Monday", Weekday::Monday}, 
		{"Tuesday", Weekday::Tuesday},
		{"Wednesday", Weekday::Wednesday},
		{"Thursday", Weekday::Thursday},
		{"Friday", Weekday::Friday},
		{"Saturday", Weekday::Saturday},
		{"Sunday", Weekday::Sunday},
	};
	return days[day];

}

void addWorker(Register& workers, std::string name) {
	std::cout << "----------------------------------" << std::endl;
	std::cout << "1) Add worker" << std::endl;
	std::cout << "2) Add ticket seller" << std::endl;
	std::cout << "3) Add food seller" << std::endl;
	std::cout << "4) Add janitor" << std::endl;

	unsigned short answer;
	std::cout << "> ";
	std::cin >> answer;

	unsigned short hours;
	std::cout << "hours per week: ";
	std::cin >> hours;

	switch (answer) {
		case 1:
			workers.addWorker(name, hours);
			break;
		case 2:
			std::cout << "cash ID: ";
			std::cin >> answer;
			workers.addTicketSeller(name, hours, answer);
			break;
		case 3:
			workers.addFoodSeller(name, hours);
			break;
		case 4:
			workers.addJanitor(name, hours);
			break;
	}
}

void options(Register& workers) {
	std::cout << "----------------------------------" << std::endl;
	std::cout << "1) Add worker" << std::endl;
	std::cout << "2) Calculate bonus" << std::endl;
	std::cout << "3) Calculate salary for" << std::endl;
	std::cout << "4) Add availability for worker" << std::endl;
	std::cout << "5) Remove availability for worker" << std::endl;
	std::cout << "6) Add availability for all" << std::endl;
	std::cout << "7) Remove availability for all" << std::endl;
	std::cout << "8) Calculate total salary" << std::endl << std::endl;
	std::cout << "9) Exit" << std::endl;

	unsigned short answer;
	std::cout << "> ";
	std::cin >> answer;

	std::string name;
	std::string day;
	Weekday weekday;

	if (answer < 6) {
		std::cout << "name: ";
		std::cin >> name;
	}
	
	if (answer >= 4 && answer < 8) {
		std::cout << "day: ";
		std::cin >> day;
		weekday = getWeekday(day);

	}
	
	switch (answer) {
		case 1:
			addWorker(workers, name);
			break;
		case 2:
			std::cout << "Performance: ";
			std::cin >> answer;
			answer = workers.calculateBonusFor(name, answer);
			std::cout << "the bonus is: " << answer;
			break;
		case 3:
			std::cout << "Bonus: ";
			std::cin >> answer;
			workers.calculateSalaryFor(name, answer);
			break;
		case 4:
			workers.addAvailabilityFor(name, weekday);
			break;
		case 5:
			workers.removeAvailabilityFor(name, weekday);
			break;
		case 6:
			workers.addAvailabilityForAll(weekday);
			break;
		case 7:
			workers.removeAvailabilityForAll(weekday);
			break;
		case 8:
			std::cout << "Total salary: ";
			std::cout << workers.calculateTotalSalary() << std::endl;
			break;
		case 9:
			exit(1);
			break;
		default:
			break;

	}
}

int main(int argc, char* argv[]) {
	Register workers;
	while (true) {
		std::cout << std::endl;
		std::cout << "Total salary: ";
		std::cout << workers.calculateTotalSalary() << std::endl;
		std::cout << workers;
		std::cout << std::endl;
		options(workers);
	}
}
