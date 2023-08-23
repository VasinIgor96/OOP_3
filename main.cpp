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
        std::cout << "Оберіть опцію:\n";
        std::cout << "1. Додати водойму\n";
        std::cout << "2. Видалити водойму\n";
        std::cout << "3. Вивести список водойм\n";
        std::cout << "4. Зберегти до текстового файлу\n";
        std::cout << "5. Зберегти до бінарного файлу\n";
        std::cout << "6. Перевірка належності до одного типу\n";
        std::cout << "7. Порівняння площі водойм одного типу\n";
        std::cout << "8. Копіювання об’єктів\n";
        std::cout << "9. Вийти\n";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string name;
            double width, length, maxDepth;
            std::cout << "Введіть назву водойми: ";
            std::getline(std::cin, name);
            std::cout << "Введіть ширину: ";
            std::cin >> width;
            std::cout << "Введіть довжину: ";
            std::cin >> length;
            std::cout << "Введіть максимальну глибину: ";
            std::cin >> maxDepth;

            reservoirs.push_back(Reservoir(name, width, length, maxDepth));
            break;
        }
        case 2: {
            if (!reservoirs.empty()) {
                int index;
                std::cout << "Введіть індекс водойми для видалення: ";
                std::cin >> index;

                if (index >= 0 && index < reservoirs.size()) {
                    reservoirs.erase(reservoirs.begin() + index);
                }
                else {
                    std::cout << "Некоректний індекс.\n";
                }
            }
            else {
                std::cout << "Список водойм порожній.\n";
            }
            break;
        }
        case 3: {
            if (!reservoirs.empty()) {
                for (int i = 0; i < reservoirs.size(); ++i) {
                    std::cout << "Водойма #" << i << "\n";
                    reservoirs[i].display();
                    std::cout << "Площа: " << reservoirs[i].calculateArea() << " кв. м\n";
                }
            }
            else {
                std::cout << "Список водойм порожній.\n";
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
                std::cout << "Дані збережено до текстового файлу.\n";
            }
            else {
                std::cout << "Помилка відкриття файлу.\n";
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
                std::cout << "Дані збережено до бінарного файлу.\n";
            }
            else {
                std::cout << "Помилка відкриття файлу.\n";
            }
            break;
        }
        case 6: {
            if (reservoirs.size() >= 2) {
                int index1, index2;
                std::cout << "Введіть індекс першої водойми: ";
                std::cin >> index1;
                std::cout << "Введіть індекс другої водойми: ";
                std::cin >> index2;

                if (index1 >= 0 && index1 < reservoirs.size() && index2 >= 0 && index2 < reservoirs.size()) {
                    if (reservoirs[index1].isSameType(reservoirs[index2])) {
                        std::cout << "Водойми належать до одного типу.\n";
                    }
                    else {
                        std::cout << "Водойми не належать до одного типу.\n";
                    }
                }
                else {
                    std::cout << "Некоректний індекс.\n";
                }
            }
            else {
                std::cout << "Необхідно щонайменше 2 водойми для порівняння.\n";
            }
            break;
        }
        case 7: {
            if (reservoirs.size() >= 2) {
                int index1, index2;
                std::cout << "Введіть індекс першої водойми: ";
                std::cin >> index1;
                std::cout << "Введіть індекс другої водойми: ";
                std::cin >> index2;

                if (index1 >= 0 && index1 < reservoirs.size() && index2 >= 0 && index2 < reservoirs.size()) {
                    if (reservoirs[index1].isSameType(reservoirs[index2])) {
                        double area1 = reservoirs[index1].calculateArea();
                        double area2 = reservoirs[index2].calculateArea();
                        if (area1 > area2) {
                            std::cout << "Перша водойма більша за площею.\n";
                        }
                        else if (area1 < area2) {
                            std::cout << "Друга водойма більша за площею.\n";
                        }
                        else {
                            std::cout << "Водойми мають однакову площу.\n";
                        }
                    }
                    else {
                        std::cout << "Водойми не належать до одного типу, порівняння неможливе.\n";
                    }
                }
                else {
                    std::cout << "Некоректний індекс.\n";
                }
            }
            else {
                std::cout << "Необхідно щонайменше 2 водойми для порівняння.\n";
            }
            break;
        }
        case 8: {
            if (!reservoirs.empty()) {
                int index;
                std::cout << "Введіть індекс водойми для копіювання: ";
                std::cin >> index;

                if (index >= 0 && index < reservoirs.size()) {
                    reservoirs.push_back(reservoirs[index]);
                    std::cout << "Водойму скопійовано.\n";
                }
                else {
                    std::cout << "Некоректний індекс.\n";
                }
            }
            else {
                std::cout << "Список водойм порожній.\n";
            }
            break;
        }
        case 9: {

            return 0;
        }
        default: {
            std::cout << "Некоректний вибір. Спробуйте ще раз.\n";
            break;
        }
        }
    } while (choice != 9);

    return 0;
}
