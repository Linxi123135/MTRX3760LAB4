#include "CircuitFileReader.h"
#include "CircuitManager.h"
#include <iostream>
//********************************************************
int main() {
    // Step 1: Read the circuit description file.
    CircuitFileReader fileReader("C:/1aA_Sydney/2023 S2/MTRX3760/Lab4/fulladder.txt");
    if (!fileReader.parseFile()) {
        std::cerr << "Failed to parse circuit description file." << std::endl;
        return 1;
    }

    // Step 2: Create and configure components and connections
    CircuitManager circuitManager;

    auto componentsInfo = fileReader.getComponents();
    for (const auto& info : componentsInfo) {
        CComponent* component = CComponent::createComponent(info.type, info.name);
        circuitManager.addComponent(component);
    }

    auto connectionsInfo = fileReader.getConnections();
    for (const auto& info : connectionsInfo) {
        circuitManager.connectComponents(info.sourceName, info.destName, info.pin);
    }

    // Step 3: Run the simulation
    circuitManager.runSimulation();

    return 0;
}
