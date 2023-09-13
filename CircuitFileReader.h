#ifndef CIRCUIT_FILE_READER_H
#define CIRCUIT_FILE_READER_H

#include <string>
#include <vector>

struct ComponentInfo {
    std::string type;
    std::string name;
};

struct ConnectionInfo {
    std::string sourceName;
    std::string destName;
    int pin;
};

class CircuitFileReader {
public:
    CircuitFileReader(const std::string& filePath);
    bool parseFile();

    std::vector<ComponentInfo> getComponents() const;
    std::vector<ConnectionInfo> getConnections() const;

private:
    std::string filePath;
    std::vector<ComponentInfo> components;
    std::vector<ConnectionInfo> connections;
};

#endif // CIRCUIT_FILE_READER_H
