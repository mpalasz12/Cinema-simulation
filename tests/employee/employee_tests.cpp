#include "catch_amalgamated.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <stdexcept>
#include "../../src/day.hpp"
#include "../../src/worker.hpp"
#include "../../src/schedule.hpp"
#include "../../src/register.hpp"
#include "../../src/enums.hpp"
#include "../../src/cinema.hpp"
#include "../../src/workplace.hpp"

TEST_CASE("Daily schedule tests", "[day]") {
	Day day(10, 18);

	CHECK(day.getStartTime() == 10);
	CHECK(day.getEndTime() == 18);

	SECTION("setting valid dates") {
		CHECK(day.setStartTime(9));
		CHECK(day.setEndTime(19));
	}

	SECTION("setting invalid dates") {
		CHECK_FALSE(day.setEndTime(6));
		CHECK_FALSE(day.setStartTime(22));
	}
}

TEST_CASE("Weekly schedule tests", "[schedule]") {
	Schedule schedule;
	CHECK(schedule.getWeekNum() == 0);

	std::vector<Weekday> availability;
	availability.push_back(Weekday::Monday);
	availability.push_back(Weekday::Tuesday);
	availability.push_back(Weekday::Wednesday);
	availability.push_back(Weekday::Thursday);
	availability.push_back(Weekday::Friday);

	schedule.assembleScheduleEvening(40, availability, 20);
	
	SECTION("Check if the schedule assembled correctly") {
		Day day = schedule.getDay(Weekday::Monday);
		CHECK(day.getStartTime() == 12);
		CHECK(day.getEndTime() == 20);
		Day weekend = schedule.getDay(Weekday::Saturday);
		CHECK_FALSE(weekend.isWorking());
	}

	schedule.assembleScheduleEvening(38, availability, 20);

	SECTION("more schedule checks") {
		Day day = schedule.getDay(Weekday::Tuesday);
		CHECK(day.getStartTime() == 13);
		CHECK(day.getEndTime() == 20);
	}
}

TEST_CASE("Worker tests", "[worker]") {
	Worker worker("worker", 10);

	CHECK(worker.getName() == "worker");
	CHECK(worker.getWage() == 18);

	SECTION("availability checks") {
		worker.addAvailability(Weekday::Monday);
		worker.addAvailability(Weekday::Tuesday);
		CHECK(worker.isAvailable(Weekday::Monday));
		CHECK_FALSE(worker.isAvailable(Weekday::Wednesday));
	}

	worker.addAvailability(Weekday::Monday);
	worker.addAvailability(Weekday::Tuesday);
	worker.assembleSchedule(10);

	unsigned bonus = worker.calculateBonus(80);

	SECTION("bonus tests") {
		CHECK(bonus == 80);
		worker.addAvailability(Weekday::Saturday);
		worker.assembleSchedule(15);
		bonus = worker.calculateBonus(80);
		CHECK(bonus == 130);
	}


	SECTION("salary tests") {
		worker.calculateSalary(bonus);
		CHECK(worker.getSalary() == 260);
	}

}

TEST_CASE("Derived workers tests", "[worker]") {
	TicketSeller seller("seller", 20);
	
	CHECK(seller.getName() == "seller");
	CHECK(seller.getWage() == 20);
	CHECK(seller.getHours() == 20);

	seller.addAvailability(Weekday::Wednesday);
	seller.addAvailability(Weekday::Saturday);

	unsigned bonus;
	
	seller.assembleSchedule(20);

	 SECTION("bonus tests") {
		bonus = seller.calculateBonus(180);
		CHECK(bonus == 180);
		bonus = seller.calculateBonus(0);
		CHECK(bonus == 0);
	 }
	
	SECTION("salary tests") {
		bonus = seller.calculateBonus(100);
		seller.calculateSalary(bonus);
		CHECK(seller.getSalary() == 500);

		seller.addAvailability(Weekday::Monday);
		seller.addAvailability(Weekday::Friday);

		seller.calculateSalary(bonus);
		CHECK(seller.getSalary() == 540);
	}
}

TEST_CASE("Register tests", "[register]") {
	Register workers;
	workers.addWorker("john", 20);
	workers.addWorker("mark", 20);
	workers.addTicketSeller("david", 20);
	workers.addJanitor("anna", 20);

	SECTION("finding tests") {
		CHECK_NOTHROW(workers.findWorkerByName("john"));
		CHECK_THROWS(workers.findWorkerByName("max"));
	}

	SECTION("availability tests") {
		workers.addAvailabilityFor("john", Weekday::Monday);
		Worker worker = workers.findWorkerByName("john");
		CHECK(worker.isAvailable(Weekday::Monday));
		CHECK_FALSE(worker.isAvailable(Weekday::Tuesday));
		Worker worker2 = workers.findWorkerByName("mark");

		CHECK_FALSE(worker2.isAvailable(Weekday::Monday));
	}

	SECTION("availability for all tests") {
		workers.addAvailabilityForAll(Weekday::Saturday);
		Worker worker = workers.findWorkerByName("john");
		CHECK(worker.isAvailable(Weekday::Saturday));
		Worker worker2 = workers.findWorkerByName("anna");
		CHECK(worker2.isAvailable(Weekday::Saturday));
	}

	SECTION("total salary tests (no bonus)") {
		workers.addAvailabilityForAll(Weekday::Monday);
		workers.addAvailabilityForAll(Weekday::Saturday);
		CHECK(workers.calculateTotalSalary() == 1500);
	}

	SECTION("individual salary tests") {
		workers.addAvailabilityForAll(Weekday::Monday);
		workers.addAvailabilityForAll(Weekday::Saturday);
		unsigned bonus = workers.calculateBonusFor("john", 100);
		CHECK(bonus == 150);
		bonus = workers.calculateBonusFor("david", 100);
		CHECK(bonus == 100);
		
		workers.calculateSalaryFor("john", 150);
		workers.calculateSalaryFor("david", 100);
		Worker worker1 = workers.findWorkerByName("john");
		Worker worker2 = workers.findWorkerByName("david");
		CHECK(worker1.getSalary() == 510);
		CHECK(worker2.getSalary() == 500);
	}
}

TEST_CASE("Cinema tests", "[cinema]") {
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

	CHECK(cinema.hasEmployee(0, WorkplaceType::ticketCounter));
	CHECK_FALSE(cinema.hasEmployee(1, WorkplaceType::ticketCounter));

}
