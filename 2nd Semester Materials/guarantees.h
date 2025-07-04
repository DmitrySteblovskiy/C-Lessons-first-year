#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

// Strong safety guarantee
class MyContainer {
public:
    MyContainer() = default;

    // Конструктор копирования: может выбросить исключение, если, например,
    // std::vector не сможет выделить память, но это происходит до изменения текущего объекта
    MyContainer(const MyContainer& other) = default;

    // Constructor: other -> other2, this -> this2
    // operation A: other, this
    // operation B: other2, this2 (exception fault)

    // Оператор присваивания через идиому copy-and-swap для strong exception safety
    MyContainer& operator=(MyContainer other) {  // throw exception
        swap(*this, other);  // noexcept => this == valid
        return *this;
    }

/* Идиома copy‑and‑swap:

1. Параметр оператора принимается по значению (== копируется) с помощью copy constructor
2. Затем делаем swap внутреннего состояния текущего объекта и нашей копии
3. Swap должен быть noexcept, чтобы гарантировать невыбрасывание исключений при обмене

Если во время копирования (на шаге 1) возникнет исключение, то исходный объект остаётся неизменным !!!
а операция присваивания будет all‑or‑nothing == strong guarantee exception safety !!!
*/
    // Функция swap должна быть noexcept !!!
    friend void swap(MyContainer& first, MyContainer& second) noexcept {
        using std::swap;
        swap(first.data, second.data);
    }

    void add(int value) {
        // Если emplace_back выбросит исключение, объект останется неизменным, поскольку изменение происходит через copy-and-swap
        data.emplace_back(value);
    }

    void print() const {
        for (int v : data)
            std::cout << v << " ";
        std::cout << "\n";
    }

private:
    std::vector<int> data;  // 10^9 * 4 bt
};


class MyContainer2 {
public:
    MyContainer2() = default;

    // Конструктор копирования
    MyContainer2(const MyContainer2& other) : data(other.data) {}

    // Оператор присваивания с базовой гарантией exception safety:
    // Если во время копирования элементов возникнет исключение, контейнер останется валидным,
    // но может оказаться частично заполненным.
    MyContainer2& operator=(const MyContainer2& other) {
        if (this == &other)
            return *this;

        // Очищаем текущее содержимое.
        data.clear();

        // Копируем элементы по одному.
        // Если push_back выбросит исключение, часть элементов уже будет добавлена,
        // но инварианты std::vector сохранятся.
        for (const auto& elem : other.data) {
            data.emplace_back(elem);
        }
        // 1 2 3
        //-^- => exception => invalid data

        return *this;
    }

    void add(int value) {
        data.push_back(value);
    }

    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> data;
};
