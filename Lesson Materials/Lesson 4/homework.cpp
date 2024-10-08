/*
Вам в качестве входных данных поступают два массива одинаковой чётной длины из натуральных чисел.
Одному массиву нужно выделить память с помощью new, другому - с помощью сишного оператора malloc/calloc на Ваше усмотрение.
Далее "перемешайте" элементы массива так, чтобы в первом остались лишь элементы с чётным индексом
(то есть на нечетные индексы 1 массива были помещены элементы, находившиеся во 2 массиве под четными номерами),
а во втором - с нечётным индексом. Оставшиеся за бортом элементы нас не интересуют. Выведите оба массива по очереди.

К каждому ключевому действию (выделению памяти, освобождению, созданию вспомогательных массивов и функций,
ко всяиким ифам и циклам) жду пояснения в комментах к коду.

Старайтесь также не забывать про Google C++ Codestyle:
https://google.github.io/styleguide/cppguide.html
*/

#include <iostream>
#include <cassert> // Для тестирования
#include <cstdlib> // Для malloc и free

// Функция для перемешивания массивов
void MixArrays(...) {}

// Функция для вывода массивов. Можно вызвать из MixArrays, или передать измененные после MixArrays массивы.
// Во втором случае MixArrays на вряд ли останется void.
void PrintMixedArrays(...) {}

int main() {
    // Выделение памяти и ввод массивов
    ...

    // Перемешивание массивов
    MixArrays(...);

    // Вывод массивов
    PrintMixedArrays(...);

    // Освобождение памяти
    ...
}

// Примеры и тесты находятся в соседнем файле test.cpp
