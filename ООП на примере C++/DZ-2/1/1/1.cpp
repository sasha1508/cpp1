// Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса. 
// Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения. 
// Создать счетчик количества созданных студентов. 
// В функции main() создать несколько (не больше трёх) студентов. 
// Вывести информацию о них.
//

#include <iostream>
#include <locale.h>  // Подключение русского языка
#include <string>
using namespace std;


class Person
{
public:
	Person();
	~Person();

	string name;
	int age;
	string pol;
	int weight;

	void SetName(string _name)	{ name = _name; }
	void SetAge(int _age) { age = _age; }
	void SetGender(string _pol) { pol = _pol; }
	void SetWeight(int _weight) { weight = _weight; }

private:
	
};

Person::Person()
{
	
}

Person::~Person()
{
	
}


class Student : public Person
{
public:
	Student();
	~Student();

	
	int year;
	static int count;

	void SetYear(int _year)  { year = _year; }
	void PlasYear()  { year++; }
	static void printCount()
	{
		cout << "Всего создано студентов: " << count << "\n\n";
	}
	void print()
	{
		cout << "Имя студента: " << name << "\n";
		cout << "Возраст: " << age << "\n";
		cout << "Пол: " << pol << "\n";
		cout << "Вес: " << weight << "\n";
		cout << "Год обучения: " << year << "\n\n";
	}
private:

};

int Student::count = 0;

Student::Student()
{
	Person();
	count++;
}

Student::~Student()
{
	count--;
}

int main()
{
	setlocale(LC_ALL, "Russian"); // Подключение русского языка

	Student* Sasha = new Student();
	Sasha->SetName("Cаша");
	Sasha->SetAge(18);
	Sasha->SetGender("Мужской");
	Sasha->SetWeight(55);
	Sasha->SetYear(2);
	Student* Vova = new Student();
	Vova->SetName("Вова");
	Vova->SetAge(17);
	Vova->SetGender("Мужской");
	Vova->SetWeight(50);
	Vova->SetYear(1);
	Student* Kolya = new Student();
	Kolya->SetName("Коля");
	Kolya->SetAge(20);
	Kolya->SetGender("Мужской");
	Kolya->SetWeight(70);
	Kolya->SetYear(4);
	//delete Vova;
	Student::printCount();
	Sasha->print();
	Vova->print();
	Kolya->print();
}
