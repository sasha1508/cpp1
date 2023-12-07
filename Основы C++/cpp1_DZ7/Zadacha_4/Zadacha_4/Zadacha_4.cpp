// * Объявить структуру Сотрудник с различными полями. 
// Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. 
// Выделите динамически переменную этого типа. Инициализируйте ее. 
// Выведите ее на экран и ее размер с помощью sizeof. 
// Сохраните эту структуру в текстовый файл.
//

#include <string>
#include <iostream>

using namespace std;

#pragma pack(push, 1)
struct Sotrudnik
{
    string FIO;
    int age;
    string professiya;
};
#pragma pack(pop)

int main()
{
    Sotrudnik* sotr1 = new Sotrudnik;
    sotr1->FIO = "Ivanov I.I.";
    sotr1->age = 35;
    sotr1->professiya = "Programmer";

    cout << sotr1->FIO << endl;
    cout << sotr1->age << endl;
    cout << sotr1->professiya << endl;

    cout << endl << "Size: ";
    cout << sizeof(*sotr1) << endl;

    
}
