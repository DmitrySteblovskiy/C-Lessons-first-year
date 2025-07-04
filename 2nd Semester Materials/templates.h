#pragma once

#include <iostream>

template <typename T, typename U>
class Calculator {
public:
    Calculator() = default;  // bruh // stop dissing my constructor  // oke

    ~Calculator() = default;  // ? // All questions to Anya  // Anya, excuse me? /
    
long double Multiply (T a, U b) {
    return a * b;
}

long double Add(T a, U b) {  // If I surplus size_t a and size_t b couldn't it get out of bounds?
    return a + b;
}

long double Substraction(T a, U b) {
    return a - b;  // unsigned 
}

// Anya
T RemainderDivide (const T a, const T b) {
    if (!std::is_integral<T>::value) {  // for unsigned only?
        throw std::invalid_argument('Integer Error');
    }

    if (!std::is_integral<U>::value && std::is_signed<U>::value) {
        throw std::invalid_argument('Integer Error');
    }

    if (b == 0) {
        throw std::invalid_argument('Zero Division Error');
    }

    return a % b;
}

long double Division(T a, U b) {  // b = 10^-12
    if (b == static_cast<U>(0)) {
        throw std::invalid_argument("Zero Division Error");
    }

    return  static_cast<long double>(a) / b;
}

private:
  T a{0};  // mb default values?
  T b{0};
};
