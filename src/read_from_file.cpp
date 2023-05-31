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
Weekday convertToWeekdayType(const int& weekday) {
    static const std::unordered_map<int, Weekday> weekdayTypeMap = {
        {0, Weekday::Monday},
        {1, Weekday::Tuesday},
        {2, Weekday::Wednesday},
        {3, Weekday::Thursday},
        {4, Weekday::Friday},
        {5, Weekday::Saturday},
        {6, Weekday::Sunday}
    };

    auto it = weekdayTypeMap.find(weekday);
    if (it != weekdayTypeMap.end()) {
        return it->second;
    }

    return Weekday::Monday;
}
