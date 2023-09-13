#include "CircuitManager.h"
#include <iostream>

// Add a component to the circuit
void CircuitManager::addComponent(CComponent* component) {
    components[component->getName()] = component;
}

// Connect two components
void CircuitManager::connectComponents(const std::string& sourceName, const std::string& destName, int pin) {
    if (components.find(sourceName) == components.end() || components.find(destName) == components.end()) {
        std::cerr << "Error: Invalid component names for connection.\n";
        return;
    }
    // For this simplified example, we'll assume that connections are represented by signals
    signals[destName] = signals[sourceName];
}

// Run the simulation for Full Adder and Half Adder
void CircuitManager::runSimulation() {
    // Assuming that the input signals are set (this is just an example)
    signals["A"] = true;
    signals["B"] = false;
    signals["Cin"] = true;

    // Loop through all components and update their outputs based on their inputs
    for (const auto& kv : components) {
        const std::string& componentName = kv.first;
        CComponent* component = kv.second;

        // Gather inputs for this component (simplified)
        std::vector<bool> inputs;
        if (componentName == "Sum" || componentName == "Cout") {
            inputs.push_back(signals["A"]);
            inputs.push_back(signals["B"]);
            inputs.push_back(signals["Cin"]);
        }

        // Perform the logic operation for this component
        bool output = component->performLogic(inputs);

        // Update the output of this component (simplified)
        signals[componentName] = output;
    }

    // Output the results (simplified)
    std::cout << "Sum: " << signals["Sum"] << std::endl;
    std::cout << "Cout: " << signals["Cout"] << std::endl;
}
