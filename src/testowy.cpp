#include "cinema.hpp"
#include "read_from_file.h"
#include "simlog.hpp"
#include <iostream>

int main()
{
    SimLog sim;
    sim.addToStepLog("Jakies napisy");
    sim.addToStepLog("elo");
    sim.addToStepLog("iajsindnfadj");
    sim.addToStepLog("elo");
    sim.clearStepLog();
    sim.writeStepLogToFile("wyjscie.txt");
}