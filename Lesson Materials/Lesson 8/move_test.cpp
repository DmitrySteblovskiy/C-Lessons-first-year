#include <iostream>
#include <vector>
#include <chrono>
#include <utility>

template <typename T>
void swap_copy(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

template <typename T>
void swap_move(T& a, T& b) {
    T c = std::move(a);
    a = std::move(b);
    b = std::move(c);
}

int main() {
    // Пример с векторами большого размера для демонстрации преимуществ move-семантики
    std::vector<int> vec1(10000000, 1);
    std::vector<int> vec2(10000000, 2);

    // Измеряем время swap_copy
    auto start_copy = std::chrono::high_resolution_clock::now();
    swap_copy(vec1, vec2);
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto duration_copy = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();
    std::cout << "Swap using copy: " << duration_copy << " microseconds\n";

    // Измеряем время swap_move
    auto start_move = std::chrono::high_resolution_clock::now();
    swap_move(vec1, vec2);
    auto end_move = std::chrono::high_resolution_clock::now();
    auto duration_move = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();
    std::cout << "Swap using move: " << duration_move << " microseconds\n";
}


/*
Swap using copy: 45167 microseconds
Swap using move: 1 microseconds
*/
