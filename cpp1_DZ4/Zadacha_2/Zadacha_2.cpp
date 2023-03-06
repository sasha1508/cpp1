// Написать программу, выводящую на экран строку “true”, если две целочисленные константы, 
// объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти.Иначе "false".

#include <iostream>
#include <locale.h>  // Подключение русского языка
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка

    const int chislo1 = 5;
    const int chislo2 = 6;

    string result = "Ложь";

    result = ((chislo1 == 10 && chislo2 == 10) || (chislo1 + chislo2) == 10) ? "Правда" : "Ложь";

    std::cout << "Результат: " << result << endl;

    return 0;
}
