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
        std::cout << "6. �������� ��������� �� ������ ����\n";
        std::cout << "7. ��������� ����� ������ ������ ����\n";
        std::cout << "8. ��������� �ᒺ���\n";
        std::cout << "9. �����\n";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string name;
            double width, length, maxDepth;
            std::cout << "������ ����� �������: ";
            std::getline(std::cin, name);
            std::cout << "������ ������: ";
            std::cin >> width;
            std::cout << "������ �������: ";
            std::cin >> length;
            std::cout << "������ ����������� �������: ";
            std::cin >> maxDepth;

            reservoirs.push_back(Reservoir(name, width, length, maxDepth));
            break;
        }
        case 2: {
            if (!reservoirs.empty()) {
                int index;
                std::cout << "������ ������ ������� ��� ���������: ";
                std::cin >> index;

                if (index >= 0 && index < reservoirs.size()) {
                    reservoirs.erase(reservoirs.begin() + index);
                }
                else {
                    std::cout << "����������� ������.\n";
                }
            }
            else {
                std::cout << "������ ������ �������.\n";
            }
            break;
        }
        case 3: {
            if (!reservoirs.empty()) {
                for (int i = 0; i < reservoirs.size(); ++i) {
                    std::cout << "������� #" << i << "\n";
                    reservoirs[i].display();
                    std::cout << "�����: " << reservoirs[i].calculateArea() << " ��. �\n";
                }
            }
            else {
                std::cout << "������ ������ �������.\n";
            }
            break;
        }
        case 4: {
            std::ofstream file("reservoirs.txt");
            if (file.is_open()) {
                for (const Reservoir& reservoir : reservoirs) {
                    file << reservoir.getName() << " " << reservoir.getWidth() << " " << reservoir.getLength() << " " << reservoir.getMaxDepth() << "\n";
                }
                file.close();
                std::cout << "��� ��������� �� ���������� �����.\n";
            }
            else {
                std::cout << "������� �������� �����.\n";
            }
            break;
        }
        case 5: {
            std::ofstream file("reservoirs.bin", std::ios::binary);
            if (file.is_open()) {
                for (const Reservoir& reservoir : reservoirs) {
                    file.write(reinterpret_cast<const char*>(&reservoir), sizeof(Reservoir));
                }
                file.close();
                std::cout << "��� ��������� �� �������� �����.\n";
            }
            else {
                std::cout << "������� �������� �����.\n";
            }
            break;
        }
        case 6: {
            if (reservoirs.size() >= 2) {
                int index1, index2;
                std::cout << "������ ������ ����� �������: ";
                std::cin >> index1;
                std::cout << "������ ������ ����� �������: ";
                std::cin >> index2;

                if (index1 >= 0 && index1 < reservoirs.size() && index2 >= 0 && index2 < reservoirs.size()) {
                    if (reservoirs[index1].isSameType(reservoirs[index2])) {
                        std::cout << "������� �������� �� ������ ����.\n";
                    }
                    else {
                        std::cout << "������� �� �������� �� ������ ����.\n";
                    }
                }
                else {
                    std::cout << "����������� ������.\n";
                }
            }
            else {
                std::cout << "��������� ���������� 2 ������� ��� ���������.\n";
            }
            break;
        }
        case 7: {
            if (reservoirs.size() >= 2) {
                int index1, index2;
                std::cout << "������ ������ ����� �������: ";
                std::cin >> index1;
                std::cout << "������ ������ ����� �������: ";
                std::cin >> index2;

                if (index1 >= 0 && index1 < reservoirs.size() && index2 >= 0 && index2 < reservoirs.size()) {
                    if (reservoirs[index1].isSameType(reservoirs[index2])) {
                        double area1 = reservoirs[index1].calculateArea();
                        double area2 = reservoirs[index2].calculateArea();
                        if (area1 > area2) {
                            std::cout << "����� ������� ����� �� ������.\n";
                        }
                        else if (area1 < area2) {
                            std::cout << "����� ������� ����� �� ������.\n";
                        }
                        else {
                            std::cout << "������� ����� �������� �����.\n";
                        }
                    }
                    else {
                        std::cout << "������� �� �������� �� ������ ����, ��������� ���������.\n";
                    }
                }
                else {
                    std::cout << "����������� ������.\n";
                }
            }
            else {
                std::cout << "��������� ���������� 2 ������� ��� ���������.\n";
            }
            break;
        }
        case 8: {
            if (!reservoirs.empty()) {
                int index;
                std::cout << "������ ������ ������� ��� ���������: ";
                std::cin >> index;

                if (index >= 0 && index < reservoirs.size()) {
                    reservoirs.push_back(reservoirs[index]);
                    std::cout << "������� ����������.\n";
                }
                else {
                    std::cout << "����������� ������.\n";
                }
            }
            else {
                std::cout << "������ ������ �������.\n";
            }
            break;
        }
        case 9: {

            return 0;
        }
        default: {
            std::cout << "����������� ����. ��������� �� ���.\n";
            break;
        }
        }
    } while (choice != 9);

    return 0;
}
