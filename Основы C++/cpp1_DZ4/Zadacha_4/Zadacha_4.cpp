// Со звёздочкой.Написать программу, проверяющую, является ли некоторое число - простым.
// Простое число — это целое положительное число, которое делится без остатка только на единицу и себя само.

#include <iostream>
#include <locale.h>  // Подключение русского языка

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка

    int chislo;

    cout << "Введи число: ";
    cin >> chislo;

    bool chisloProstoe = true;

    for (int i = 2; i < chislo; i++)
    {
         if (chislo % i == 0)  chisloProstoe = false;
    }

    cout << endl;

    if (chisloProstoe) cout << "Число простое" << endl;
    else cout << "Число НЕ простое" << endl;
}
