#include "CircuitFileReader.h"
#include <fstream>
#include <sstream>
//****************
CircuitFileReader::CircuitFileReader(const std::string& filePath) : filePath(filePath) {}

bool CircuitFileReader::parseFile() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string keyword;
        iss >> keyword;

        if (keyword == "component") {
            std::string type, name;
            iss >> type >> name;
            components.push_back({type, name});
        } else if (keyword == "wire") {
            std::string sourceName, destName;
            int pin;
            iss >> destName >> pin >> sourceName;
            connections.push_back({sourceName, destName, pin});
        }
        // Additional parsing logic can be added here for testerInput and testerOutput
    }

    return true;
}

std::vector<ComponentInfo> CircuitFileReader::getComponents() const {
    return components;
}

std::vector<ConnectionInfo> CircuitFileReader::getConnections() const {
    return connections;
}
