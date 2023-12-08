// DZ-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <cstdint>
#include <stdlib.h>

class Power
{
public:
	Power() {}
	~Power() {}

	void set(int _number1, int _number2)
	{
		number1 = _number1;
		number2 = _number2;
	}
	double calculate()
	{
		return  pow(number1, number2);
	}

private:
	int number1 = 2, number2 = 2;
};

class RGBA
{
public:
	RGBA(int _m_red = 0, int _m_green = 0, int _m_blue = 0, int _m_alpha = 255)
	{
		m_red = _m_red;
		m_green = _m_green;
		m_blue = _m_blue;
		m_alpha = _m_alpha;
	}
	~RGBA() {}

	void print() 
	{
		std::cout << m_red << ", " << m_green << ", " << m_blue << ", " << m_alpha << "\n";
		//std::cout << m_red;
	}

private:
	int m_red, m_green, m_blue, m_alpha;
};



int main()
{
	Power power = Power();
	power.set(5, 10);
	double pow = power.calculate();
    std::cout << pow << "\n";
	RGBA rgba = RGBA(1, 1, 1);
	rgba.print();
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
