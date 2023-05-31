#include <iostream>
#include <fstream>
#include "simlog.hpp"

SimLog::SimLog() {
	stepLog = "";
}

std::string SimLog::getStepLog() {
	return stepLog;
}

void SimLog::setStepLog(std::string text) {
	stepLog = text;
}

void SimLog::addToStepLog(std::string entry) {
	stepLog.append(entry);
	stepLog.append("\n");
}

void SimLog::clearStepLog() {
	log.push_back(stepLog);
	stepLog = "";
}
void SimLog::writeStepLogToFile(const std::string& filename)
{
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) 
	{
        for (const auto& entry : log) 
		{
            outputFile << entry << std::endl;
        }
        outputFile.close();
        std::cout << "Step log written to file: " << filename << std::endl;
    } 
	else 
	{
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
