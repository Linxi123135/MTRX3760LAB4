#ifndef CIRCUIT_MANAGER_H
#define CIRCUIT_MANAGER_H

#include "CComponent.h"
#include <map>
#include <string>
#include <vector>

class CircuitManager {
public:
    // Add a component to the circuit
    void addComponent(CComponent* component);

    // Connect two components
    void connectComponents(const std::string& sourceName, const std::string& destName, int pin);

    // Run the simulation for Full Adder and Half Adder
    void runSimulation();

private:
    std::map<std::string, CComponent*> components;  // Map of components by name
    // Additional data structures for connections and wiring can be added here

    std::map<std::string, bool> signals;  // Signals for each component
};

#endif // CIRCUIT_MANAGER_H
//
