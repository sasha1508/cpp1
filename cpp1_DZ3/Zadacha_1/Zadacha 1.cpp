// Написать программу, вычисляющую выражение a* (b + (c / d)) и выводящую результат с плавающей точкой, 
// где a, b, c, d – целочисленные константы.
// Используйте static_cast или С - Style cast к float чтобы выполнить точное деление.


#include <iostream>

int main()
{
    int a, b, c, d;
    a = 10;
    b = 12;
    c = 50;
    d = 4;

    double result = a * (b + static_cast<double>(c) / static_cast<double>(d));

    std::cout << "Rezult: " << result << std::endl;
}

