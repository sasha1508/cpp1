// Выделить в памяти динамический одномерный массив типа int.
// Размер массива запросить у пользователя.Инициализировать его числами степенями двойки : 1, 2, 4, 8, 16, 32, 64, 128 ... 
// Вывести массив на экран.Не забыть освободить память. = ) Разбить программу на функции.
//

#include <iostream>
#include <locale.h>  // Подключение русского языка
#include <cmath>
using namespace std;

void AddToArray(size_t n, int ptr[])
{
    for (size_t i = 0; i < n; i++)
    {
        ptr[i] = pow(2, i);
    }
}

void PrintArray(size_t n, int ptr[])
{
    for (size_t i = 0; i < n - 1; i++)
    {
        cout << ptr[i] << ", ";
    }
    cout << ptr[n - 1];
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка

    size_t n;
    cout << "Введи число N:";
    cin >> n;
    int* ptr = new int[n];

    AddToArray(n, ptr);
    PrintArray(n, ptr);    

    delete[] ptr;
}
