// ** Написать функцию, которой передается не пустой одномерный целочисленный массив, 
// она должна вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны.
// Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance([2, 1, 1, 2, 1]) → false, 
// checkBalance([10, || 1, 2, 3, 4]) → true.
// Абстрактная граница показана символами || , эти символы в массив не входят.
//
#include <iostream>

using namespace std;
#include <locale.h>  // Подключение русского языка

bool Ravno(int array[], int size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }
    if (sum % 2 != 0) return false;
    else
    {
        int i = 0;
        int temp = 0;
        while (temp < (sum / 2))
        {
            temp += array[i];
            i++;
        }
        if (temp == (sum / 2)) return true;
    }
    return false;
}

void printArray(int array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i == size - 1) cout << array[i];
        else cout << array[i] << ", ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка

    const int size = 6;
    int array[size] = { 1, 8, 5, 1, 8, 7 };
    printArray(array, size);
 
    if (Ravno(array, size)) cout << "Истина" << endl;
    else cout << "Ложь" << endl;
}

