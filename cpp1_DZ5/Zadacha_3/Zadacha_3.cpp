/* Задать пустой целочисленный массив размером 8. 
Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. 
Вывести массив на экран.
*/

#include <iostream>

using namespace std;

void insertToArray(int array[], int size)
{
	int j = 1;
	for (size_t i = 0; i < size; i++)
	{
		array[i] = j;
		j += 3;
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
	const int size = 8;
	int array[size];
	insertToArray(array, size);
	printArray(array, size);
}
