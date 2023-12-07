// Написать программу, проверяющую что сумма двух(введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), 
// если да – вывести строку "true", в противном случае – "false";

#include <iostream>
#include <locale.h>  // Подключение русского языка
#include <string>


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка

    int cislo1;
    int cislo2;

    cout << "Введи число 1: ";
    cin >> cislo1;

    cout << "Введи число 2: ";
    cin >> cislo2;

    string rezult = "false";
    int sum = cislo1 + cislo2;

    rezult = (sum >= 10 && sum <= 20) ? "true" : "false";

    std::cout << "Сумма чисел в пределах от 10 до 20 - " << rezult << endl;
}

