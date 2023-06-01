#include <iostream>
#include <sstream>
#include <string>
#include "src/simulation.hpp"

int main(int argc, char *argv[]) 
{
	if(argc != 7)
    {
        std::cerr << "Incorrect number of command line arguments - expected 6, got " << argc - 1<< std::endl;
        return 1;
    }

	std::string cinemaData;
	std::string movieData;
	std::string employeeData;
	std::string counterData;
	unsigned opening;
	unsigned closing;

	std::stringstream stream;
    stream << argv[1];
	stream >> cinemaData;
	stream.clear();

	stream << argv[2];
	stream >> movieData;
	stream.clear();

	stream << argv[3];
	stream >> employeeData;
	stream.clear();

	stream << argv[4];
	stream >> counterData;
	stream.clear();

	stream << argv[5];
	stream >> opening;
	stream.clear();

	stream << argv[6];
	stream >> closing;
	stream.clear();


	//Wywolanie symulacji z dodatkowymi zmiennymi, czyli sciezkami do odpowiednich plikow
	Simulation sim("kino", opening, closing);
	sim.setRoomsPath(cinemaData);
	sim.setEmployeePath(employeeData);
	sim.setMoviePath(movieData);
	sim.setWorkplacePath(counterData);
	sim.startSimulation();
	std::string answer = "";

	bool running = true;
	while (running) {
		std::cout << sim.runStep() << std::endl;
		std::cin >> answer;
		if (answer == "exit") {
			running = false;
		}


	}

}
