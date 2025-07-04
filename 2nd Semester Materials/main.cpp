#include <any>
#include <array>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <map>
#include <memory>

struct Point { int x, y; };

Point make_point(int x, int y) { return {x, y}; }

struct S { std::string str; int value; };

S make_S() { return {"hello", 42}; }


int main() {
    int aboba = 45;
  std::shared_ptr<int> a(new int(45));

}

