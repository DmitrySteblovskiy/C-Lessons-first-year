#pragma once

#include <iostream>  // ONLY for std::cout, actually is unnec.
#include <iterator>


template <typename T>
class MyRandomAccessIterator {
public:
    // iterator_traits
    using value_type        = T;
    using reference         = T&;
    using pointer           = T*;
    using difference_type   = std::ptrdiff_t;
    using iterator_category = std::random_access_iterator_tag;

    MyRandomAccessIterator() : ptr_(nullptr) {}
    MyRandomAccessIterator(const MyRandomAccessIterator&) = default;
    MyRandomAccessIterator& operator=(const MyRandomAccessIterator&) = default;
    ~MyRandomAccessIterator() = default;

    explicit MyRandomAccessIterator(T* ptr) : ptr_(ptr) {}

    reference operator*() const { return *ptr_; }
    pointer operator->() const { return ptr_; }

    // Префиксный инкремент
    MyRandomAccessIterator& operator++() {
        ++ptr_;
        return *this;
    }

    // Постфиксный инкремент
    MyRandomAccessIterator operator++(int) {
        MyRandomAccessIterator temp = *this;
        std::cout << "this ptr: " << ptr_ << "\n";
        ++(*this);
        return temp;
    }

    // Префиксный декремент
    MyRandomAccessIterator& operator--() {
        --ptr_;
        return *this;
    }

    // Постфиксный декремент
    MyRandomAccessIterator operator--(int) {
        MyRandomAccessIterator temp = *this;
        --ptr_;
        return temp;
    }

    // Оператор сложения - создает новый итератор, сдвинутый на n
    MyRandomAccessIterator operator+(difference_type n) const {
        return MyRandomAccessIterator(ptr_ + n);
    }

    // Оператор разности между двумя итераторами = итератор, сдвинутый назад
    MyRandomAccessIterator operator-(difference_type n) const {
        return MyRandomAccessIterator(ptr_ - n);
    }

    // Оператор разности, возвращает distance между двумя iter
    difference_type operator-(const MyRandomAccessIterator& other) const {
        return ptr_ - other.ptr_;
    }

    MyRandomAccessIterator& operator+=(difference_type n) {
        ptr_ += n;
        return *this;
    }

    MyRandomAccessIterator& operator-=(difference_type n) {
        return (*this += -n);
    }

    reference operator[](difference_type n) const {
        return *(ptr_ + n);
    }

    // Позволяет выполнять сложения по типу "n + iterator"
    friend MyRandomAccessIterator operator+(difference_type n, const MyRandomAccessIterator& it) {
        return it + n;
    }
    
    friend bool operator==(const MyRandomAccessIterator& lhs, const MyRandomAccessIterator& rhs) {
        return lhs.ptr_ == rhs.ptr_;
    }
    friend bool operator!=(const MyRandomAccessIterator& lhs, const MyRandomAccessIterator& rhs) {
        return !(lhs == rhs);
    }
    friend bool operator<(const MyRandomAccessIterator& lhs, const MyRandomAccessIterator& rhs) {
        return lhs.ptr_ < rhs.ptr_;
    }
    friend bool operator>(const MyRandomAccessIterator& lhs, const MyRandomAccessIterator& rhs) {
        return rhs < lhs;
    }
    friend bool operator<=(const MyRandomAccessIterator& lhs, const MyRandomAccessIterator& rhs) {
        return !(rhs < lhs);
    }
    friend bool operator>=(const MyRandomAccessIterator& lhs, const MyRandomAccessIterator& rhs) {
        return !(lhs < rhs);
    }

private:
    T* ptr_{nullptr};
};

// Проверка соответствия концепту std::forward_iterator
static_assert(std::random_access_iterator<MyRandomAccessIterator<int>>);
static_assert(std::random_access_iterator<MyRandomAccessIterator<double>>);
static_assert(std::random_access_iterator<MyRandomAccessIterator<std::string>>);
