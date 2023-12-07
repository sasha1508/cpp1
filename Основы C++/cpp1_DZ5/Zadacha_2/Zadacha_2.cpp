// Задать целочисленный массив, состоящий из элементов 0 и 1. 
// Например: [1, 1, 0, 0, 1, 0, 1, 1, 0, 0] .
// Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.

#include <iostream>

using namespace std;

void printArray(int array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }
    cout << endl;
}

void invers(int array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == 1) array[i] = 0;
        else array[i] = 1;
    }
}

int main()
{
    const int size = 12;
    int array[size] = { 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0 };
    printArray(array, size);
    invers(array, size);
    printArray(array, size);
}
