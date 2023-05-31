#include "catch_amalgamated.hpp"
#include <iostream>
#include <sstream>
#include "../../src/movie.h"
#include "../../src/random_movies.h"

TEST_CASE("movie simple tests", "[movie]")
{
	Movie movie("Interstellar", 22, 156);

	CHECK(movie.getName() == "Interstellar");
	CHECK(movie.getPrice() == 22);
	CHECK(movie.getDuration() == 156);

	SECTION("testing setters")
	{
		movie.setName("Forrest Gump");
		movie.setPrice(15);
		movie.setDuration(140);

		CHECK(movie.getName() == "Forrest Gump");
		CHECK(movie.getPrice() == 15);
		CHECK(movie.getDuration() == 140);
	}

	SECTION("testing operator")
	{
		std::ostringstream oss;
		oss << movie;
		CHECK(oss.str() == "Movies name: Interstellar\nMovies price: 22\nMovies length: 156 minutes\n");
	}

	SECTION("random movie")
	{
		Movie random = randomMovie("example.txt");
		CHECK(random.getName() == "Interstellar");
		CHECK(random.getPrice() == 22);
		CHECK(random.getDuration() == 156);
	}
}
