﻿// Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) 
// во втором модуле mylib объявить 3 функции: 
// - для инициализации массива (типа float), 
// - печати его на экран 
// - и подсчета количества отрицательных и положительных элементов. 
// Вызывайте эти 3-и функции из main для работы с массивом.
//

// * Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).

#include <iostream>
#include "mylib.h"
#include <locale.h>  // Подключение русского языка

using namespace std;
using namespace modul1;

int main()
{
    setlocale(LC_ALL, "Russian"); // Подключение русского языка
    const size_t size = 10;
    float Array[size];
    insertToArray(Array, size);
    printArray(Array, size);
    pozitiveNegativeCount(Array, size);

}