#pragma once
#include <string>
#include <vector>

class SimLog {
	private:
		std::string stepLog;
		std::vector<std::string> log;

	public:
		SimLog();

		std::string getStepLog();
		void setStepLog(std::string text);

		void addToStepLog(std::string entry); // add a string to the log, will be ended with std::endl
		void clearStepLog(); // clear step log and add it to log
		void writeStepLogToFile(const std::string& filename);


};
