#pragma once

#include <type_traits>

template <typename T>  // T = int&&, T = std::vector&
constexpr T&& MyForward(std::remove_reference<T>& a) noexcept // T&
{
    return static_cast<T&&>(a);
}
