#include "CComponent.h"
#include <stdexcept>
enum eLogicLevel {
    LOGIC_LOW,
    LOGIC_HIGH,
    LOGIC_UNDEFINED
};
// Factory method for creating components
CComponent* CComponent::createComponent(const std::string& type, const std::string& name) {
    if (type == "AND") {
        return new AndGate(name);
    } else if (type == "OR") {
        return new OrGate(name);
    } else if (type == "XOR") {
        return new XorGate(name);
    } else if (type == "NOT") {
        return new NotGate(name);
    } else {
        throw std::invalid_argument("Unknown component type: " + type);
    }
}

// Constructor for CComponent
CComponent::CComponent(const std::string& name) : name(name) {
}

// Getter for the name
std::string CComponent::getName() const {
    return name;
}

// AndGate constructor and performLogic implementation
AndGate::AndGate(const std::string& name) : CComponent(name) {
}

bool AndGate::performLogic(const std::vector<bool>& inputs) {
    // Implement AND logic here
    eLogicLevel NewVal = LOGIC_LOW;

    // Assuming inputs[0] and inputs[1] correspond to mInputs[0] and mInputs[1] in your existing code
    if (inputs[0] == LOGIC_UNDEFINED || inputs[1] == LOGIC_UNDEFINED) {
        NewVal = LOGIC_UNDEFINED;
    } else if (inputs[0] == LOGIC_HIGH && inputs[1] == LOGIC_HIGH) {
        NewVal = LOGIC_HIGH;
    }

    // Assuming mOutputValues[0] corresponds to the return value of performLogic
    return (NewVal == LOGIC_HIGH);
}

// OrGate constructor and performLogic implementation
OrGate::OrGate(const std::string& name) : CComponent(name) {
}

bool OrGate::performLogic(const std::vector<bool>& inputs) {
    // Implement OR logic here
    eLogicLevel NewVal = LOGIC_LOW;

    if (inputs[0] == LOGIC_UNDEFINED || inputs[1] == LOGIC_UNDEFINED) {
        NewVal = LOGIC_UNDEFINED;
    } else if (inputs[0] == LOGIC_HIGH || inputs[1] == LOGIC_HIGH) {
        NewVal = LOGIC_HIGH;
    }

    return (NewVal == LOGIC_HIGH);
}

// XorGate constructor and performLogic implementation
XorGate::XorGate(const std::string& name) : CComponent(name) {
}

bool XorGate::performLogic(const std::vector<bool>& inputs) {
    // Implement XOR logic here
    eLogicLevel NewVal = LOGIC_LOW;

    if (inputs[0] == LOGIC_UNDEFINED || inputs[1] == LOGIC_UNDEFINED) {
        NewVal = LOGIC_UNDEFINED;
    } else if (inputs[0] != inputs[1]) {
        NewVal = LOGIC_HIGH;
    }

    return (NewVal == LOGIC_HIGH);
}

// NotGate constructor and performLogic implementation
NotGate::NotGate(const std::string& name) : CComponent(name) {
}

bool NotGate::performLogic(const std::vector<bool>& inputs) {
    // Implement NOT logic here
    eLogicLevel NewVal = LOGIC_LOW;

    if (inputs[0] == LOGIC_UNDEFINED) {
        NewVal = LOGIC_UNDEFINED;
    } else if (inputs[0] == LOGIC_LOW) {
        NewVal = LOGIC_HIGH;
    }

    return (NewVal == LOGIC_HIGH);
}
