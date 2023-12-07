// * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), 
// при этом метод должен циклически сместить все элементы массива на n позиций.
//

#include <iostream>

using namespace std;

void sdvigArray(int array[], int size, int sdvig)
{
	int temp;

	if (sdvig < 0)
	{
		sdvig *= -1;
		for (int j = 0; j < sdvig; j++)
		{
			temp = array[0];
			for (int i = 1; i < size; i++)
			{
				array[i - 1] = array[i];
			}
			array[size - 1] = temp;
		}
	}
	else
	{
		for (int j = 0; j < sdvig; j++)
		{
			temp = array[size-1];
			for (int i = 0; i < size-1; i++)
			{
				array[size-1-i] = array[size-2-i];
			}
			array[0] = temp;
		}
	}
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
    const int size = 6;
    int array[size] = { 1, 8, 6, 2, 4, 6 };
    int sdvig = -1;
	printArray(array, size);
    sdvigArray(array, size, sdvig);
	printArray(array, size);
}
