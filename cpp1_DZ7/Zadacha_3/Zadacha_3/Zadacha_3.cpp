// Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. 
// Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). 
// Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
//

#include <iostream>
#include <locale.h>  // Подключение русского языка

using namespace std;

#define SIZE 10
#define SwapINT(a, b) swap(a, b)

void printArray(int array[], int size)
{
	for (size_t i = 0; i < size-1; i++)
	{
		cout << array[i] << ", ";
	}

	cout << array[SIZE - 1] << endl;
}

void bubbleSort(int list[], int listLength)
{
	while (listLength--)
	{
		bool swapped = false;

		for (int i = 0; i < listLength; i++)
		{
			if (list[i] > list[i + 1])
			{
				SwapINT(list[i], list[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian"); // Подключение русского языка

    int array[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Элемент массива " << i << ": ";
		cin >> array[i];
	}
  	printArray(array, SIZE);
	bubbleSort(array, SIZE);
	printArray(array, SIZE);
}
