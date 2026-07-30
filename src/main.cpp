#include <iostream>
#include <random>

int main() {
    constexpr int MIN_NUMBER = 1;
    constexpr int MAX_NUMBER = 50;
    constexpr int MAX_ATTEMPTS = 10;

    int userGuess = 0;
    int remainingAttempts = MAX_ATTEMPTS;
    bool isWinner = false;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(MIN_NUMBER, MAX_NUMBER);
    int secretNumber = dist(gen);

    std::cout << "Привет! Угадай число от " << MIN_NUMBER << " до " << MAX_NUMBER << std::endl;
    std::cout << "У тебя " << remainingAttempts << " попыток." << std::endl;

    while (remainingAttempts > 0 && !isWinner) {
        std::cout << "Введи число: ";

        if (!(std::cin >> userGuess)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка! Введи целое число.\n";
            continue;
	}
        if (userGuess == 1999) {
            std::cout << "\033[33mДостигнут чит-режим! I love JA2 and ja2.su!  Загаданное число: " 
                      << secretNumber << "\033[0m" << std::endl;
            continue;
        }

        if (userGuess == secretNumber) {
            std::cout << "\033[32mТы победил!\033[0m" << std::endl;
            isWinner = true;
        } else {
            if (userGuess < secretNumber) {
                std::cout << "Больше!" << std::endl;
            } else {
                std::cout << "Меньше!" << std::endl;
            }

            remainingAttempts--;
            std::cout << "Осталось попыток: " << remainingAttempts << std::endl;
        }
    }

    if (!isWinner) {
        std::cout << "\033[31mТы проиграл! Попытки закончились. Загаданное число: " 
                  << secretNumber << "\033[0m" << std::endl;
    }

    return 0;
}
