#include <iostream>
#include <sstream>
#include <string>

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

	std::stringstream stream;
    stream << argv[1];
	stream >> cinemaData;
	stream.clear();

	stream << argv[2];
	stream >> movieData;
	stream.clear();

	stream << argv[3];
	stream >> employeeData;

	//Wywolanie symulacji z dodatkowymi zmiennymi, czyli sciezkami do odpowiednich plikow


}
