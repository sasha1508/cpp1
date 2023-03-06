// Написать функцию которая выводит массив double чисел на экран.
// Параметры функции это сам массив и его размер.Вызвать эту функцию из main.

#include <iostream>

using namespace std;


void printArray(double array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << " | ";
    }
    cout << endl;
}

int main()
{
    const int size = 5;
    double array[size] = { 1.7,4,5.85,7,2 };
    printArray(array, size);
}
