#include <iostream>
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
	stepLog = "";
}
