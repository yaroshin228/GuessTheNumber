#include <iostream>
#include <random>

using namespace std;
int main() {

    // Переменные
    int guess;
    int min = 1;
    int max = 50;
    int attempts = 10;
    
    // Инициализация рандомного числа
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    
    // Переменная рандомного числа
    int secret = dist(gen);
    
    // Приветствие
    cout << "Привет! Угадай число от " << min << " до " << max << endl;
    cout << "У тебя " << attempts << " попыток." << endl;

    // Основной цикл
    while (guess != secret && attempts > 0) {

        cout << "Введи число: ";
        
        if (!(cin >> guess)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Введи число!\n";
            continue;
        }
        
        if (guess < secret) cout << "Больше!\n";
        else if (guess > secret) cout << "Меньше!\n";
        else {
            cout << "\033[32mТы победил!\033[0m" << endl;
            break;
        }
        attempts--;
        cout << "Осталось попыток: " << attempts << "\n";

        if (attempts == 0) {
            cout << "\033[31mТы проиграл! Попытки закончились.\033[0m";
            break;
        }
    }

    return 0;

}
