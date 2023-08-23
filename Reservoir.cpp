#include <iostream>
#include "Reservoir.h"

Reservoir::Reservoir() : name(""), width(0), length(0), maxDepth(0) {}

Reservoir::Reservoir(const std::string& name, double width, double length, double maxDepth)
    : name(name), width(width), length(length), maxDepth(maxDepth) {}

std::string Reservoir::getName() const {
    return name;
}

double Reservoir::getWidth() const {
    return width;
}

double Reservoir::getLength() const {
    return length;
}

double Reservoir::getMaxDepth() const {
    return maxDepth;
}

double Reservoir::calculateVolume() const {
    return width * length * maxDepth;
}

double Reservoir::calculateArea() const {
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const {

    return maxDepth == other.maxDepth;
}

Reservoir::Reservoir(const Reservoir& other) {

    name = other.name;
    width = other.width;
    length = other.length;
    maxDepth = other.maxDepth;
}

Reservoir::~Reservoir() {

}

Reservoir& Reservoir::operator=(const Reservoir& other) {

    if (this != &other) {
        name = other.name;
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}

void Reservoir::display() const {
    std::cout << "Назва: " << name << "\n";
    std::cout << "Ширина: " << width << " м\n";
    std::cout << "Довжина: " << length << " м\n";
    std::cout << "Максимальна глибина: " << maxDepth << " м\n";
}
