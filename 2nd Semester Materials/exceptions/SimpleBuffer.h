#pragma once

#include <algorithm>
#include <stdexcept>

class SimpleBuffer {
public:
    // Конструктор: пытается выделить память, может выбросить исключение (например, std::bad_alloc)
    explicit SimpleBuffer(size_t n) : data(new int[n]), size(n) {
        // Инициализируем данные нулями
        std::fill(data, data + size, 0);
    }

    // Деструктор: гарантированно не выбрасывает исключений
    ~SimpleBuffer() noexcept {
        delete[] data;
    }

    // Копирующий конструктор: выделение памяти может выбросить исключение
    SimpleBuffer(const SimpleBuffer& other) : data(new int[other.size]), size(other.size) {
        std::copy(other.data, other.data + size, data);
    }

    // Перемещающий конструктор: просто переносим указатель и размер, noexcept
    SimpleBuffer(SimpleBuffer&& other)  noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    // Копирующее присваивание: может выбросить исключение, поэтому не(!!!) noexcept
    SimpleBuffer& operator=(const SimpleBuffer& other) noexcept(false) {
        if (this != &other) {
            // Создаём временный объект для безопасного копирования
            SimpleBuffer temp(other);
            std::swap(data, temp.data);
            std::swap(size, temp.size);
        }
        return *this;
    }

    // Перемещающее присваивание: просто переносим данные, noexcept
    SimpleBuffer& operator=(SimpleBuffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }


    // Метод для получения размера буфера: гарантированно не выбрасывает исключений
    [[nodiscard]] size_t getSize() const noexcept {
        return size;
    }

    // Метод доступа с проверкой границ: выбрасывает std::out_of_range при неверном индексе
    int& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        return data[index];
    }

private:
    int* data;
    size_t size;
};
