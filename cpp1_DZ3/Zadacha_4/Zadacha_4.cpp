// ** Написать программу, вычисляющую выражение из первого задания, 
// а переменные для неё объявлены и инициализировать в другом cpp файле.Используйте extern.

#include <iostream>

extern int a, b, c, d;

int main()
{
  
    double result = a * (b + static_cast<double>(c) / static_cast<double>(d));

    std::cout << "Rezult: " << result << std::endl;
}