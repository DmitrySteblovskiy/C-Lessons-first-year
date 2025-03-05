#include <iostream>
#include <iterator>
#include <vector>

#include "iterators.h"


// Учимся считать расстояние между итераторами для произвольной штуки
template<typename Iterator>
typename std::iterator_traits<Iterator>::difference_type myDistance(Iterator first, Iterator last) {
    typename std::iterator_traits<Iterator>::difference_type diff = 0;

    while (first != last) {
        ++first;
        ++diff;
    }

    return diff;
}


int main() {
    // А давайте попробуем с помощью нашего итератора вывести C-style массив:
    int arr[] = {1, 2, 3, 4, 5};
    MyRandomAccessIterator<int> start(arr);
    MyRandomAccessIterator<int> finish(arr + 5);
    std::cout << "Элементы массива:\n";
    for (auto it = start; it != finish; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // Тестим работу с std::vector, расшариваем про .data() = указатель на начало
    // или на конец, если добавить size() вектора. Также помним про .begin(), .end()
    std::vector<int> vec {10, 20, 30, 40, 50};
    MyRandomAccessIterator<int> vbegin(vec.data());
    MyRandomAccessIterator<int> vend(vec.data() + vec.size());
    std::cout << "Элементы vector:\n";
    for (auto it = vbegin; it != vend; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    // Посравниваем итераторы
    std::cout << "Проверяем итераторы на сравнение:\n";
    std::cout << "start < finish ? : " << (start < finish) << "\n";
    std::cout << "finish < start ? : " << (finish < start) << "\n\n";

    // Посчитаем дистанцию между итераторами
    std::ptrdiff_t dist = finish - start;
    std::cout << "Дистанция между start и finish: " << dist << "\n\n";

    // Тест 5: Проверка оператора []
    std::cout << "Третий элемент массива: " << start[2] << "\n";
}
