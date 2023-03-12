// * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово 
// в указанном пользователем файле (для простоты работаем только с латиницей). 
// Используем функцию find которая есть в строках std::string.
//

#include <iostream>
#include <fstream>
#include <string>

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

int main()
{
    string test = ReadFile("Test.txt");
    string slovo = "file";
    if (test.find(slovo) != string::npos) cout << "Yes";
    else cout << "No";
}
