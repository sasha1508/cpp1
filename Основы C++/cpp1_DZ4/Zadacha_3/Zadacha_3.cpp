// Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. 
// Например: "Your numbers: 1 3 5 7 9 11 13 …".Для решения используйте любой С++ цикл.

#include <iostream>

using namespace std;

int main()
{
    for(int i = 1; i < 50; i += 2)
    { 
        cout << i << " ";
    }
    cout << endl;   
}
