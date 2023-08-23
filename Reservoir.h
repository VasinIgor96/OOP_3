#include <iostream>
#include <string>

class Reservoir {
private:
    std::string name;
    double width;
    double length;
    double maxDepth;

public:
    Reservoir();
    Reservoir(const std::string& name, double width, double length, double maxDepth);

    std::string getName() const;
    double getWidth() const;
    double getLength() const;
    double getMaxDepth() const;

    double calculateVolume() const;
    double calculateArea() const;
    bool isSameType(const Reservoir& other) const;

    Reservoir(const Reservoir& other);

    ~Reservoir();

    Reservoir& operator=(const Reservoir& other);

    void display() const;
};
