// Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
// У Fruit есть две переменные-члена: name (имя) и color (цвет). 
// Добавить новый класс GrannySmith, который наследует класс Apple.

#include <iostream>
#include <locale.h>  // Подключение русского языка
#include "Apple.h";
#include "Banana.h";
#include "GrannySmith.h";

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка

    Apple newApple = Apple();
    newApple.name = "Яблоко";
    newApple.color = "красный";
    Banana newBanana = Banana();
    newBanana.name = "Банан";
    newBanana.color = "жёлтый";
    GrannySmith newGrannySmith = GrannySmith();
    newGrannySmith.name = "Что-то похожее на яблоко";
    newGrannySmith.color = "жёлто-красный";

    std::cout << newApple.name << ", " << newApple.color << "\n";
    std::cout << newBanana.name << ", " << newBanana.color << "\n";
    std::cout << newGrannySmith.name << ", " << newGrannySmith.color << "\n";
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
