﻿// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>  // Подключение русского языка

class Stack
{
public:
	Stack() {};
	~Stack() {};

	void reset()
	{
		count = 0;
		for (size_t i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
	}

	bool push(int number)
	{
		if (count >= 10) return false;
		arr[count] = number;
		count++;
		return true;
	}

	int pop()
	{
		if (count - 1 < 0)
		{
			std::cout << "Массив не заполнен!\n";
			return 0;
		}
		count--;
		return arr[count - 1];
	}

	void print()
	{
		std::cout << "( ";
		for (size_t i = 0; i < count; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << ")\n";
	}

private:
	int arr[10];
	int count;
};


int main()
{
	setlocale(LC_ALL, "Russian"); // Подключение русского языка

	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
