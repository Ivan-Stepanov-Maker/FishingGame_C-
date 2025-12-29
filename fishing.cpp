#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>

struct NumbersFish {
    // Количество рыб
    int bassNum = 0;
    int pikeNum = 0;
    int crucianCarpNum = 0;
    int carpNum = 0;
};

struct Fish {
    std::string bass = "bass";   // Названия видов рыб
    std::string pike = "pike";
    std::string crucianCarp = "crucian carp";
    std::string carp = "carp";
};

int inputInt() {
    int value;
    while (!(std::cin >> value)) {
        std::cout << "Need an integer!\n";
        std::cin.clear();           // Очистка состояния потока ввода
        std::cin.ignore(1000, '\n');// Удаление некорректных символов
    }
    return value;
}

char inputChar() {
    char ch;
    while (!(std::cin >> ch)) {
        std::cout << "Need a character!\n";
        std::cin.clear();           // Очистка состояния потока ввода
        std::cin.ignore(1000, '\n');// Удаление некорректных символов
    }
    return ch;
}

void showInventory(const NumbersFish& catching) {
    std::cout << "Bass: " << catching.bassNum << std::endl;
    std::cout << "Pike: " << catching.pikeNum << std::endl;
    std::cout << "Crucian Carp: " << catching.crucianCarpNum << std::endl;
    std::cout << "Carp: " << catching.carpNum << std::endl;
}

int main() {
    Fish fish;
    NumbersFish catching;

    // Рандомизация вида рыбы
    srand(static_cast<unsigned>(time(nullptr)));
    const std::string* peacefulFishes[] = {&fish.crucianCarp, &fish.carp};     // Миролюбивые виды
    const std::string* predatoryFishes[] = {&fish.bass, &fish.pike};          // Хищники
    int randomIndex = rand() % 2;                                             // Генерируем случайный индекс

    // Баланс игрока
    double balance = 0;

    while (true) {
        std::cout << "Welcome to fishing game written in C++! Choose a fishing style:\n"
                  << "(1) Peaceful\n"
                  << "(2) Predatory\n";
        
        int style = inputInt();
        
        if (style == 1) {
            std::cout << "We'll be catching peaceful fish.\n";
            std::cout << "Throw the fishing rod by pressing 'D':\n";
            char opD = inputChar();
            if (opD == 'D') {
                std::cout << "Line is out...\n";
                Sleep(10000);       // Пауза перед поклевкой
                
                std::cout << "Quickly reel her in! Press 'C':\n";
                char opC = inputChar();
                if (opC == 'C') {
                    std::cout << "Caught a " << *peacefulFishes[randomIndex] << "!\n";
                    
                    std::cout << "Sell or keep?\n(S)-Sell, (T)-Inventory:\n";
                    char opS = inputChar();
                    
                    if (opS == 'S') {
                        if (*peacefulFishes[randomIndex] == fish.crucianCarp) {
                            std::cout << "Sold fish for 3 coins.\n";
                            balance += 3;
                        } else if (*peacefulFishes[randomIndex] == fish.carp) {
                            std::cout << "Sold fish for 8 coins.\n";
                            balance += 8;
                        }
                        
                        std::cout << "Balance: " << balance << std::endl;
                    } else if (opS == 'T') {
                        if (*peacefulFishes[randomIndex] == fish.crucianCarp) {
                            ++catching.crucianCarpNum;
                        } else if (*peacefulFishes[randomIndex] == fish.carp) {
                            ++catching.carpNum;
                        }
                        
                        std::cout << "Added to inventory.\n";
                        showInventory(catching);
                    } else {
                        std::cout << "Error! Try again.\n";
                        continue;
                    }
                }
            }
        } else if (style == 2) {
            std::cout << "We'll be catching predatory fish.\n";
            std::cout << "Throw the fishing rod by pressing 'D':\n";
            char opD = inputChar();
            if (opD == 'D') {
                std::cout << "Line is out...\n";
                Sleep(10000);      // Пауза перед поклевкой
                
                std::cout << "Quickly reel her in! Press 'C':\n";
                char opC = inputChar();
                if (opC == 'C') {
                    std::cout << "Caught a " << *predatoryFishes[randomIndex] << "!\n";
                    
                    std::cout << "Sell or keep?\n(S)-Sell, (T)-Inventory:\n";
                    char opS = inputChar();
                    
                    if (opS == 'S') {
                        if (*predatoryFishes[randomIndex] == fish.bass) {
                            std::cout << "Sold fish for 10 coins.\n";
                            balance += 10;
                        } else if (*predatoryFishes[randomIndex] == fish.pike) {
                            std::cout << "Sold fish for 8 coins.\n";
                            balance += 8;
                        }
                        
                        std::cout << "Balance: " << balance << std::endl;
                    } else if (opS == 'T') {
                        if (*predatoryFishes[randomIndex] == fish.bass) {
                            ++catching.bassNum;
                        } else if (*predatoryFishes[randomIndex] == fish.pike) {
                            ++catching.pikeNum;
                        }
                        
                        std::cout << "Added to inventory.\n";
                        showInventory(catching);
                    } else {
                        std::cout << "Error! Try again.\n";
                        continue;
                    }
                }
            }
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}