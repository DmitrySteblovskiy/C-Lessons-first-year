#include <array>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <map>

struct Point { int x, y; };

Point make_point(int x, int y) { return {x, y}; }

struct S { std::string str; int value; };

S make_S() { return {"hello", 42}; }


int main() {
    int arr[] = {10, 20, 30};
    auto& [a, b, c] = arr;
    a = 33;
    std::cout << arr[0] << ", " << b << ", " << c << "\n\n";

    std::array<float,3> A = {1.1f, 2.2f, 3.3f};
    auto [x, y, z] = A;        // ссылки на элементы A
    x = 11;
    std::cout << x << ", " << y << ", " << z << "\n\n";

    auto [X, Y] = make_point(31, 37);
    std::cout << "X = " << X << " Y = " << Y << "\n\n";

    const auto& [str, val] = make_S();  // str — rvalue-ссылка на временный S
    // lifetime объекта, возвращаемого make_S(), продлён до конца текущей области видимости
    std::cout << str << " " << val << "\n\n";

    std::map<std::string, int> my_map = {{"one",1},{"two",2}};
    for (auto& [key, val] : my_map) {
        std::cout << key << " -> " << val << "\n";
    }
}


using _T = std::decay_t<decltype(expr)>;  // 1. определяет «чистый» тип результата
_T __tmp = expr;                          // 2. материализует временный объект
auto a = get<0>(__tmp);                   // 3. берёт 0–й элемент или поле
auto b = get<1>(__tmp);                   // 4. берёт 1–й элемент или поле

