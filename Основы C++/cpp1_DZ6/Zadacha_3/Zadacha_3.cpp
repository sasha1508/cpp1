// Написать программу, которая создаст два текстовых файла (*.txt), 
// примерно по 50-100 символов в каждом (особого значения не имеет с каким именно содержимым). 
// Имена файлов запросить у польлзователя.
// 
// * Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).
//

#include <iostream>
#include <io.h>
#include <fstream>
#include <string>
#include <locale.h>  // Подключение русского языка
using namespace std;

string ReadFile(string Name)
{
    ifstream fout11(Name);
    string buf;
    string buf1;

    while (!fout11.eof())
    {
        getline(fout11, buf);
        buf1 += buf;
    }
    fout11.close();

    return buf1;
}

void SaveFile(string Name, string Text)
{
    ofstream fout1(Name);
    fout1 << Text;
    fout1.close();
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка

    SaveFile("my_data.txt", "Это первый файл");
    SaveFile("my_data-01.txt", "Это второй файл");

    string File1 = ReadFile("my_data.txt");
    string File2 = ReadFile("my_data-01.txt");

    cout << File1 << endl;
    cout << File2 << endl;



    SaveFile("Result.txt", File1 + "\n" + File2);

    string File3 = ReadFile("Result.txt");
    cout << File3 << endl;
}
