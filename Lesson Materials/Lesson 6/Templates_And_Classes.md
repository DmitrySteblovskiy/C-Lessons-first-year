
# Перегрузка функций и шаблоны в C++

## 1. Перегрузка функций

Перегрузка функций — это возможность в C++ создавать несколько функций с одним и тем же именем, но с разными параметрами. Это позволяет вызывать нужную функцию в зависимости от переданных аргументов.

### Пример

```
// Функция для сложения двух целых чисел
int add(int a, int b) {
    return a + b;
}

// Перегруженная функция для сложения двух чисел с плавающей точкой
double add(double a, double b) {
    return a + b;
}

int main() {
    int intResult = add(5, 3);       // Вызовет int add(int, int)
    double doubleResult = add(5.5, 3.3); // Вызовет double add(double, double)
}
```

В этом примере одна функция `add` принимает и возвращает `int`, а другая принимает и возвращает `double`. В зависимости от переданных аргументов вызывается необходимая функция.



## 2. Шаблоны (Templates)

Шаблоны позволяют писать универсальный код, который может работать с различными типами данных. Это значит, что можно определить функцию или класс, которая будет работать с любым типом, указанным при создании экземпляра шаблона.

### Примеры использования шаблонов для перегрузки функций

Шаблоны можно использовать для создания обобщенной версии функции, которая будет работать с разными типами данных.

```
// Шаблонная функция для сложения двух значений
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Можно также иметь перегруженные версии шаблонных функций для специальной логики
template <>
std::string add<std::string>(std::string a, std::string b) {
    return a + " " + b;
}

int main() {
    int intResult = add(5, 3);
    double doubleResult = add(5.5, 3.3);
}
```

В этом примере шаблонная функция `add` может принимать два значения любого типа и возвращать их сумму. Мы также продемонстрировали специализацию шаблонной функции для `std::string`, чтобы она добавляла пробел между словами.



## 3. Различия в файлах .h, .hpp, .cc, .cpp, .c, их назначение и компиляция

### a) Заголовочные файлы (.h, .hpp)
- **.h**: Стандартное расширение для заголовочных файлов C/C++. Они содержат объявления функций, классов, структур и макросов. Обычно используются для разделения интерфейса и реализации.
- **.hpp**: Также используется для заголовочных файлов, часто в C++. Обычно применяются для заголовков, которые содержат шаблонные классы и функции, но это не строгая практика.

### b) Исходные файлы (.c, .cpp, .cc)
- **.c**: Расширение для исходных файлов на языке C. Они содержат определения функций и являются основной частью кода программ на C.
- **.cpp**: Служит для исходных файлов C++. Эти файлы содержат определения классов и методов для C++ программ.
- **.cc**: Тоже расширение для исходных файлов C++. Менее распространено, но многие разработчики предпочитают его в зависимости от личных или корпоративных предпочтений.

## 4. Основы классов и структур

### Классы

**Класс** в C++ — это пользовательский тип данных, который объединяет данные и функции, работающие с этими данными, в одну сущность. Классы используются для моделирования объектов реального мира и управления сложными данными.

- **Поля**: Эти переменные хранят данные внутри класса.
- **Методы**: Эти функции определяют поведение класса и работают с его данными.
- **Доступ**: Модификаторы доступа (`public`, `private`, и `protected`) контролируют доступ к членам класса.

### Структуры

**Структура** (struct) — это также пользовательский тип данных, похожий на класс. Главное отличие от классов в C++ — это, как правило, использование по умолчанию `public` доступа, в то время как у классов доступ по умолчанию `private`.

```
// Пример класса
class MyClass {
private:
    int privateField; // Только доступен внутри MyClass

public:
    int publicField;  // Доступен извне

    void publicMethod() {
        // Действие
    }
};

// Пример структуры
struct MyStruct {
    int publicField; // По умолчанию является публичным
};
```


### Конструктор

**Конструктор** — это специальный метод класса, который вызывается при создании объекта и инициализирует его. Имя конструктора совпадает с именем класса.

```
class MyClass {
public:
    MyClass() {
        // Код инициализации
    }
};
```


### Деструктор

**Деструктор** — это метод, который вызывается при уничтожении объекта. Он используется для освобождения ресурсов и выполнения очистки. Имя деструктора — это имя класса с тильдой (`~`) в начале.

```
class MyClass {
public:
    ~MyClass() {
        // Код очистки
    }
};
```


### Правило трёх

Правило трёх в C++ гласит, что если класс требует явного определения одного из следующих методов, то, **вероятно (но не обязательно)**, ему нужно определить все три:

- **Копирующий конструктор**: Метод, который создает копию объекта.
- **Оператор присваивания**: Метод, который позволяет присваивание одного объекта другому.
- **Деструктор**: Метод, который освобождает ресурсы при уничтожении объекта.

Это связано с тем, что такие классы обычно управляют ресурсами, требующими глубокого копирования или явного освобождения, например, динамически выделенной памятью.

```
class MyClass {
public:
    MyClass(const MyClass& other) {
        // Копирующий конструктор
    }

    MyClass& operator=(const MyClass& other) {
        // Оператор присваивания
        return *this;
    }

    ~MyClass() {
        // Деструктор
    }
};
```



## 5. Пример базового класса для калькулятора - ваше дз, кстати

### Класс `Calculator` в файле заголовка (`Calculator.h`)

```
class Calculator {
public:
    // Конструктор
    Calculator();

    // Деструктор
    ~Calculator();

    // Базовые методы для арифм. операций
    int Add(const int a, const int b);

    int Multiply(const int a, const int b);
};

```

### Реализация класса `Calculator` в файле исходного кода (`Calculator.cc`)

```
#include "Calculator.h"
#include <iostream>

Calculator::Calculator() {
    std::cout << "Калькулятор создан" << '\n';
}

Calculator::~Calculator() {
    std::cout << "Калькулятор ликвидирован" << '\n';
}

// Базовая реализация методов арифм. операций
int Calculator::add(const int a, const int b) {
    return a + b;
}

int Calculator::multiply(const int a, const int b) {
    return a * b;
}
```
