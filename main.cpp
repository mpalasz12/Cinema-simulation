#include "src/enums.hpp"
#include "src/workplace.hpp"
#include "src/cinema.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <stdexcept>

int main(int argc, char *argv[]) {
	Cinema cinema("cinema", 10, 22);
	cinema.addEmployee("john", employeeType::worker, 20);
	cinema.addEmployee("mark", employeeType::worker, 20);
	cinema.addEmployee("david", employeeType::ticketSeller, 20);
	cinema.addEmployee("anna", employeeType::janitor, 20);
	cinema.addAvailabilityForAll(Weekday::Monday);
	cinema.addAvailabilityForAll(Weekday::Tuesday);
	cinema.addAvailabilityForAll(Weekday::Wednesday);
	cinema.addAvailabilityForAll(Weekday::Thursday);

	cinema.addTicketCounter();
	cinema.addTicketCounter();
	cinema.addFoodCounter();
	cinema.addJanitorCloset();

	cinema.prepareEmployeeSchedules();
	cinema.prepareWorkplacesDay(Weekday::Monday);

	cinema.hasEmployee(0, WorkplaceType::ticketCounter);
}
