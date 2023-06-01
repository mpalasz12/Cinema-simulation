#include <iostream>
#include <sstream>
#include <string>
#include "src/simulation.hpp"

int main(int argc, char *argv[]) 
{
	if(argc != 4)
    {
        std::cerr << "Incorrect number of command line arguments - expected 2, got " << argc << std::endl;
        return 1;
    }

	std::string cinemaData;
	std::string movieData;
	std::string employeeData;
	std::string counterData;

	std::stringstream stream;
    stream << argv[1];
	stream >> cinemaData;
	stream.clear();

	stream << argv[2];
	stream >> movieData;
	stream.clear();

	stream << argv[3];
	stream >> employeeData;

	stream << argv[4];
	stream >> counterData;


	//Wywolanie symulacji z dodatkowymi zmiennymi, czyli sciezkami do odpowiednich plikow
	Simulation sim("kino", 10, 20);
	sim.setRoomsPath(cinemaData);
	sim.setEmployeePath(employeeData);
	sim.setMoviePath(movieData);
	sim.setWorkplacePath(counterData);
	sim.startSimulation();
	std::string answer = "";
	while (true) {
		std::cout << sim.runStep() << std::endl;
		std::cin >> answer;
		sim.getCurrentStep();

	}

}
