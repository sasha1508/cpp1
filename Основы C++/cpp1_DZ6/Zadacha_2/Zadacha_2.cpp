// Динамически выделить матрицу 4х4 типа int.
// Инициализировать ее псевдослучайными числами через функцию rand.Вывести на экран.
// Разбейте вашу программу на функции которые вызываются из main.
//
#include <iostream>
using namespace std;

void AddRandom(int** pMatrix, size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			pMatrix[i][j] = rand();
		}
	}
}

void PrintMatrix(int** pMatrix, size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			cout << pMatrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
    size_t SIZE = 4;
    int** pMatrix = new int* [SIZE]; // Выделение массива указателей на строки
	for (size_t i = 0; i < SIZE; i++) // Выделение строк матрицы
	{
		pMatrix[i] = new int[SIZE];
	}

	AddRandom(pMatrix, SIZE);
	PrintMatrix(pMatrix, SIZE);

	for (size_t i = 0; i < SIZE; i++) // Освобождение строк матрицы из памяти
	{
		delete[] pMatrix[i];
	}
	delete[] pMatrix; // Удаление из памяти массива указателей на строки 
}

