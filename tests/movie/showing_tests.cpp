#include "catch_amalgamated.hpp"
#include <iostream>
#include <sstream>
#include "../../src/showing.h"
#include "../../src/time.h"
#include "../../src/enums.hpp"

TEST_CASE("showing simple tests", "[showing]")
{
	Time time(Weekday::Monday, 10);

	CHECK(time.getDay() == Weekday::Monday);
	CHECK(time.getHour() == 10);

	Showing showing("Interstellar", time, 145, 21);
	showing.setFreeChairs(20);

	CHECK(showing.getName() == "Interstellar");
	CHECK(showing.getDay() == Weekday::Monday);
	CHECK(showing.getHour() == 10);
	CHECK(showing.getLength() == 3);
	CHECK(showing.getPrice() == 21);
	CHECK(showing.getFreeChairs() == 20);

	SECTION("testing operator")
	{
		std::ostringstream oss;
		oss << showing;
		CHECK(oss.str() == "Movies name: Interstellar\nMovies starting hour: 10:00\nMovies price: 21\nFree chairs: 20\n\n");
	}
}
