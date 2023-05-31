#include "read_from_file.h"
#include "enums.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

employeeType convertToEmployeeType(const std::string& employeeTypeName) {
    static const std::unordered_map<std::string, employeeType> employeeTypeMap = {
        {"worker", employeeType::worker},
        {"ticketSeller", employeeType::ticketSeller},
        {"foodSeller", employeeType::foodSeller},
        {"janitor", employeeType::janitor}
    };

    auto it = employeeTypeMap.find(employeeTypeName);
    if (it != employeeTypeMap.end()) {
        return it->second;
    }

    return employeeType::worker;
}
WorkplaceType convertToWorkplaceType(const std::string& workplaceTypeName) {
    static const std::unordered_map<std::string, WorkplaceType> workplaceTypeMap = {
        {"ticketCounter", WorkplaceType::ticketCounter},
        {"janitorialCloset", WorkplaceType::janitorialCloset},
        {"foodCounter", WorkplaceType::foodCounter},
        {"other", WorkplaceType::other}
    };

    auto it = workplaceTypeMap.find(workplaceTypeName);
    if (it != workplaceTypeMap.end()) {
        return it->second;
    }

    return WorkplaceType::ticketCounter;
}