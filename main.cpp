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
        std::cout << "6. Вийти\n";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            Reservoir newReservoir;
            std::cin >> newReservoir;
            reservoirs.push_back(newReservoir);
            std::cout << "Водойму додано!\n";
            break;
        }
        case 2: {
            if (!reservoirs.empty()) {
                int index;
                std::cout << "Виберіть номер водойми для видалення: ";
                std::cin >> index;

                if (index >= 0 && index < reservoirs.size()) {
                    reservoirs.erase(reservoirs.begin() + index);
                    std::cout << "Водойму видалено!\n";
                }
                else {
                    std::cout << "Некоректний номер водойми.\n";
                }
            }
            else {
                std::cout << "Список водойм порожній.\n";
            }
            break;
        }
        case 3: {
            if (!reservoirs.empty()) {
                std::cout << "Список водойм:\n";
                for (size_t i = 0; i < reservoirs.size(); ++i) {
                    std::cout << "Водойма " << i << ":\n" << reservoirs[i] << "\n";
                }
            }
            else {
                std::cout << "Список водойм порожній.\n";
            }
            break;
        }
        case 4: {
            std::string filename;
            std::cout << "Введіть ім'я текстового файлу для збереження: ";
            std::cin >> filename;

            std::ofstream outputFile(filename);
            if (outputFile.is_open()) {
                for (const Reservoir& reservoir : reservoirs) {
                    outputFile << reservoir << "\n";
                }
                outputFile.close();
                std::cout << "Дані збережено у текстовий файл " << filename << "\n";
            }
            else {
                std::cout << "Не вдалося відкрити файл для запису.\n";
            }
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Введіть ім'я бінарного файлу для збереження: ";
            std::cin >> filename;

            std::ofstream outputFile(filename, std::ios::binary);
            if (outputFile.is_open()) {
                for (const Reservoir& reservoir : reservoirs) {
                    outputFile.write(reinterpret_cast<const char*>(&reservoir), sizeof(Reservoir));
                }
                outputFile.close();
                std::cout << "Дані збережено у бінарний файл " << filename << "\n";
            }
            else {
                std::cout << "Не вдалося відкрити файл для запису.\n";
            }
            break;
        }
        case 6: {
            std::cout << "Програму завершено.\n";
            break;
        }
        default: {
            std::cout << "Некоректний вибір. Спробуйте ще раз.\n";
            break;
        }
        }

    } while (choice != 6);

    return 0;
}
