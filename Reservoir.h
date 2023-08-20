#pragma once
#include <string>
#include <iostream>

class Reservoir {
public:
    Reservoir();
    Reservoir(const std::string& name, double width, double length, double maxDepth);

    double approximateVolume() const;
    double surfaceArea() const;
    bool sameType(const Reservoir& other) const;
    bool operator<(const Reservoir& other) const;
    friend std::istream& operator>>(std::istream& is, Reservoir& reservoir);
    friend std::ostream& operator<<(std::ostream& os, const Reservoir& reservoir);

private:
    std::string name;
    double width;
    double length;
    double maxDepth;
};
