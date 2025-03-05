#pragma once

#include <iterator>
#include <string>

template <typename T>
class MyForwardIterator {
public:
    // std::iterator_traits - шаблонная структурка с основными чертами итератора
    using iterator_category = std::forward_iterator_tag;
    using value_type	      = T;
    using difference_type   = std::ptrdiff_t;
    using pointer	      = T*;
    using reference	      = T&;

    MyForwardIterator() : ptr_() {}
    ~MyForwardIterator() = default;

    explicit MyForwardIterator(T* ptr) : ptr_(ptr) {}

    MyForwardIterator(const MyForwardIterator&) = default;
    MyForwardIterator& operator = (const MyForwardIterator&) = default;

    // * this  ....  this.value()
    pointer operator->() const { return ptr_; }
    reference operator*() const { return *ptr_; }

    MyForwardIterator& operator++()
    {
        ++ptr_;
        return *this;
    }

    MyForwardIterator operator++(int)
    {
        MyForwardIterator temp = *this;
        ++(*this);
        return temp;
    }

    // left-hand side
    friend bool operator==(const MyForwardIterator& lhs, const MyForwardIterator& rhs)
    {
        return lhs.ptr_ == rhs.ptr_;
    }

    friend bool operator!=(const MyForwardIterator& lhs, const MyForwardIterator& rhs)
    {
        return !(lhs.ptr_ == rhs.ptr_);
    }

private:
    T* ptr_{nullptr};
};

// Проверка соответствия концепту
static_assert(std::forward_iterator<MyForwardIterator<int>>);
static_assert(std::forward_iterator<MyForwardIterator<double>>);
static_assert(std::forward_iterator<MyForwardIterator<std::string>>);
