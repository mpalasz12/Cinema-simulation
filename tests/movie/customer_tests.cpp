#include "catch_amalgamated.hpp"
#include "../../src/customer.h"

TEST_CASE("customer simple tests", "[customer]")
{
    Customer customer(20, 15, "Interstellar", 3);

    CHECK(customer.getID() == 20);
    CHECK(customer.getAge() == 15);
    CHECK(customer.getMovieName() == "Interstellar");
    CHECK(customer.getHowManyTickets() == 3);

    SECTION("testing setters")
    {
        customer.setID(10);
        customer.setAge(25);
        customer.setMovieName("Shrek");
        customer.setHowManyTickets(5);

        CHECK(customer.getID() == 10);
        CHECK(customer.getAge() == 25);
        CHECK(customer.getMovieName() == "Shrek");
        CHECK(customer.getHowManyTickets() == 5);
    }
}