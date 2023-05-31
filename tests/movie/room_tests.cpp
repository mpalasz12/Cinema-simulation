#include "catch_amalgamated.hpp"
#include <iostream>
#include <sstream>
#include "../../src/screening_room.h"

TEST_CASE("screening_room simple tests", "[screening_room]")
{
    ScreeningRoom room("sala1", 20);

    CHECK(room.getName() == "sala1");
    CHECK(room.getCapacity() == 20);

    SECTION("testing operator")
    {
        std::ostringstream oss;
        oss << room;
        CHECK(oss.str() == "Rooms name: sala1\nRooms maximum capacity: 20\n");
    }
}
