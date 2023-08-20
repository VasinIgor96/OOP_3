#include "Reservoir.h"

Reservoir::Reservoir() : name(""), width(0.0), length(0.0), maxDepth(0.0) {}

Reservoir::Reservoir(const std::string& name, double width, double length, double maxDepth)
    : name(name), width(width), length(length), maxDepth(maxDepth) {}

double Reservoir::approximateVolume() const {
    return width * length * maxDepth;
}

double Reservoir::surfaceArea() const {
    return width * length;
}

bool Reservoir::sameType(const Reservoir& other) const {
    return (surfaceArea() == other.surfaceArea());
}

bool Reservoir::operator<(const Reservoir& other) const {
    return (approximateVolume() < other.approximateVolume());
}

std::istream& operator>>(std::istream& is, Reservoir& reservoir) {
    std::cout << "������ ����� �������: ";
    std::getline(is, reservoir.name);
    std::cout << "������ ������ �������: ";
    is >> reservoir.width;
    std::cout << "������ ������� �������: ";
    is >> reservoir.length;
    std::cout << "������ ����������� ������� �������: ";
    is >> reservoir.maxDepth;
    is.ignore();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Reservoir& reservoir) {
    os << "�����: " << reservoir.name << "\n";
    os << "����� �������: " << reservoir.surfaceArea() << " �^2\n";
    os << "���������� �����: " << reservoir.approximateVolume() << " �^3\n";
    return os;
}
