#ifndef CCOMPONENT_H
#define CCOMPONENT_H

#include <string>
#include <vector>

// Abstract base class for all components
class CComponent {
public:
    // Factory method for creating components dynamically
    static CComponent* createComponent(const std::string& type, const std::string& name);

    // Virtual destructor for base class
    virtual ~CComponent() = default;

    // Method to get the name of the component
    std::string getName() const;

    // Virtual method to perform the logic operation; to be implemented by derived classes
    virtual bool performLogic(const std::vector<bool>& inputs) = 0;

protected:
    // Constructor is protected to prevent direct instantiation of this class
    CComponent(const std::string& name);

private:
    std::string name;
};

// Derived class for AND gate.
class AndGate : public CComponent {
public:
    AndGate(const std::string& name);
    bool performLogic(const std::vector<bool>& inputs) override;
    // ... Additional methods specific to AndGate
};

// Derived class for OR gate.
class OrGate : public CComponent {
public:
    OrGate(const std::string& name);
    bool performLogic(const std::vector<bool>& inputs) override;
    // ... Additional methods specific to OrGate
};

// Derived class for XOR gate.
class XorGate : public CComponent {
public:
    XorGate(const std::string& name);
    bool performLogic(const std::vector<bool>& inputs) override;
    // ... Additional methods specific to XorGate
};

// Derived class for NOT gate.
class NotGate : public CComponent {
public:
    NotGate(const std::string& name);
    bool performLogic(const std::vector<bool>& inputs) override;
    // ... Additional methods specific to NotGate
};

#endif // CCOMPONENT_H
