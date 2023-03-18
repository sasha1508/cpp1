#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;
namespace modul1
{
	float random(float a, float b) //a, b �������� ����� ������������ ��������
	{
		float y;
		int x;
		x = rand(); //�������� �����
		y = a + (x * (b - a)) / RAND_MAX; //�� ����� ������� �� ��� ����������...
		return y;
	}

	float* insertToArray(float array[], size_t size)
	{
		srand(time(NULL)); //��������� ��������� ����� ��������� �����
		for (size_t i = 0; i < size; i++)
		{
			array[i] = random(10, -10); //�������� �����;
		}
		return array;
	}

	void printArray(float array[], int size)
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] << endl;
		}
		cout << endl;
	}

	void pozitiveNegativeCount(float array[], int size)
	{
		size_t negative = 0;
		size_t pozitive = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] < 0)
			{
				negative++;
			}
			else
			{
				pozitive++;
			}
		}
		cout << "���������� ������������� �����: " << negative << endl << "���������� ������������� �����: " << pozitive << endl;
	}

};