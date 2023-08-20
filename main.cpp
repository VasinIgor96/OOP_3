#include <iostream>
#include <vector>
#include <fstream>
#include "Reservoir.h"
#include <windows.h>
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Reservoir> reservoirs;
    int choice;

    do {
        std::cout << "������ �����:\n";
        std::cout << "1. ������ �������\n";
        std::cout << "2. �������� �������\n";
        std::cout << "3. ������� ������ ������\n";
        std::cout << "4. �������� �� ���������� �����\n";
        std::cout << "5. �������� �� �������� �����\n";
        std::cout << "6. �����\n";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            Reservoir newReservoir;
            std::cin >> newReservoir;
            reservoirs.push_back(newReservoir);
            std::cout << "������� ������!\n";
            break;
        }
        case 2: {
            if (!reservoirs.empty()) {
                int index;
                std::cout << "������� ����� ������� ��� ���������: ";
                std::cin >> index;

                if (index >= 0 && index < reservoirs.size()) {
                    reservoirs.erase(reservoirs.begin() + index);
                    std::cout << "������� ��������!\n";
                }
                else {
                    std::cout << "����������� ����� �������.\n";
                }
            }
            else {
                std::cout << "������ ������ �������.\n";
            }
            break;
        }
        case 3: {
            if (!reservoirs.empty()) {
                std::cout << "������ ������:\n";
                for (size_t i = 0; i < reservoirs.size(); ++i) {
                    std::cout << "������� " << i << ":\n" << reservoirs[i] << "\n";
                }
            }
            else {
                std::cout << "������ ������ �������.\n";
            }
            break;
        }
        case 4: {
            std::string filename;
            std::cout << "������ ��'� ���������� ����� ��� ����������: ";
            std::cin >> filename;

            std::ofstream outputFile(filename);
            if (outputFile.is_open()) {
                for (const Reservoir& reservoir : reservoirs) {
                    outputFile << reservoir << "\n";
                }
                outputFile.close();
                std::cout << "��� ��������� � ��������� ���� " << filename << "\n";
            }
            else {
                std::cout << "�� ������� ������� ���� ��� ������.\n";
            }
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "������ ��'� �������� ����� ��� ����������: ";
            std::cin >> filename;

            std::ofstream outputFile(filename, std::ios::binary);
            if (outputFile.is_open()) {
                for (const Reservoir& reservoir : reservoirs) {
                    outputFile.write(reinterpret_cast<const char*>(&reservoir), sizeof(Reservoir));
                }
                outputFile.close();
                std::cout << "��� ��������� � ������� ���� " << filename << "\n";
            }
            else {
                std::cout << "�� ������� ������� ���� ��� ������.\n";
            }
            break;
        }
        case 6: {
            std::cout << "�������� ���������.\n";
            break;
        }
        default: {
            std::cout << "����������� ����. ��������� �� ���.\n";
            break;
        }
        }

    } while (choice != 6);

    return 0;
}
