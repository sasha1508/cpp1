// Со звёздочкой.Пользователь вводит с клавиатуры число(год) : от 1 до 3000. 
// Написать программу, которая определяет является ли этот год високосным.
// Каждый 4 - й год является високосным, кроме каждого 100 - го, 
// при этом каждый 400 - й – високосный.Вывести результаты работы программы в консоль.

#include <iostream>
#include <locale.h>  // Подключение русского языка

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка

    int year;
    bool godVisokosniy = false;

    cout << endl << "Введи номер года:";
    cin >> year;

    if (year % 4 == 0) godVisokosniy = true;
    if (year % 100 == 0) godVisokosniy = false;
    if (year % 400 == 0) godVisokosniy = true;

    if (godVisokosniy) cout << year << " - високосный год" << endl;
    else cout << year << " - НЕ високосный год" << endl;
}
