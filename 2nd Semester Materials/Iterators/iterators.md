# Итераторы в C++

Итераторы – это объекты, которые ведут себя как обобщённые указатели. Они предоставляют единый интерфейс для доступа, обхода и модификации элементов контейнеров стандартной библиотеки (STL), таких как `vector`, `list`, `map` и других. Благодаря итераторам можно абстрагироваться от внутренней реализации контейнера и использовать универсальные алгоритмы (например, `std::for_each`, `std::sort`, `std::copy`), не зависящие от конкретной структуры данных.

## Что такое итератор?

Итератор – это объект, позволяющий получить доступ к элементу контейнера и перемещаться по нему. Он действует как указатель, но при этом скрывает детали реализации структуры данных. В зависимости от возможностей итератора выделяют следующие типы.

## Зачем нужны итераторы?

- **Универсальный интерфейс:** Позволяют работать с различными типами контейнеров при помощи единого набора операций.
- **Абстракция алгоритмов:** Алгоритмы STL написаны так, чтобы работать с итераторами, что позволяет им быть независимыми от конкретного типа контейнера.
- **Удобство и безопасность:** Итераторы обеспечивают проверку границ (в некоторых случаях) и упрощают синтаксис при обходе контейнеров.

## Виды итераторов и поддерживаемые операторы

### 1. Input Iterator (итератор для чтения)
- **Описание:** Предназначен для однократного последовательного чтения элементов (однопроходный). Используется, когда необходим только доступ к элементам в режиме чтения.
- **Поддерживаемые операторы:**
  - **Разыменование:** `*it` – чтение значения.
  - **Инкремент:** `++it` или `it++` – переход к следующему элементу.
  - **Сравнение:** `==`, `!=` – проверка на равенство итераторов.

---

### 2. Output Iterator (итератор для записи)
- **Описание:** Используется для однократной последовательной записи значений в контейнер. Как правило, обеспечивает только запись (без возможности чтения ранее записанного).
- **Поддерживаемые операторы:**
  - **Разыменование:** `*it = value` – назначение нового значения в позицию итератора.
  - **Инкремент:** `++it` или `it++` – переход к следующей позиции.

---

### 3. Forward Iterator (прямой итератор)
- **Описание:** Объединяет возможности Input и Output итераторов. Поддерживает многократный проход по контейнеру с возможностью как чтения, так и записи.
- **Поддерживаемые операторы:**
  - **Разыменование:** `*it` – чтение/запись значения.
  - **Инкремент:** `++it` или `it++` – переход к следующему элементу.
  - **Сравнение:** `==`, `!=` – проверка на равенство.

---

### 4. Bidirectional Iterator (двунаправленный итератор)
- **Описание:** Расширяет функциональность Forward итераторов, добавляя возможность перемещения назад по контейнеру.
- **Поддерживаемые операторы:**
  - **Все операторы Forward итераторов.**
  - **Декремент:** `--it` или `it--` – переход к предыдущему элементу.

---

### 5. Random Access Iterator (итератор с произвольным доступом)
- **Описание:** Обеспечивает возможность не только последовательного обхода, но и произвольного доступа к элементу по индексу, аналогично указателям в C.
- **Поддерживаемые операторы:**
  - **Все операторы Bidirectional итераторов.**
  - **Арифметика с целыми числами:**
    - `it + n` – переход на n элементов вперёд.
    - `it - n` – переход на n элементов назад.
  - **Разница между итераторами:** `it2 - it1` – определение расстояния между итераторами.
  - **Индексация:** `it[n]` – доступ к элементу с индексом n относительно текущей позиции.
  - **Сравнения:** `<`, `>`, `<=`, `>=` – для сравнения позиций в контейнере.

---

## std::iterator_traits

При написании алгоритмов или своих итераторов часто возникает необходимость в получении / использовании конкретного типа итератора. Для этого в стандартной библиотеке C++ имеется шаблон `std::iterator_traits`, который определяет типы, ассоциированные с итератором. Например, для `Random Access Iterator` в `iterator_traits` записаны следующие типы:

- **value_type**: тип значения, на которое указывает итератор.
- **difference_type**: тип, используемый для представления разницы между итераторами (обычно знаковый тип, например, `std::ptrdiff_t`).
- **pointer**: тип указателя на значение.
- **reference**: тип ссылки на значение.
- **iterator_category**: тип, описывающий категорию итератора (например, `std::random_access_iterator_tag` для итераторов с произвольным доступом).

Рассмотрим пример использования `std::iterator_traits` для произвольного итератора:

```cpp
using traits = std::iterator_traits<MyRandomAccessIterator<int>>;
using value_type = traits::value_type;          // int
using difference_type = traits::difference_type; // обычно std::ptrdiff_t или другой знаковый тип
using pointer = traits::pointer;                // int*
using reference = traits::reference;            // int&
using iterator_category = traits::iterator_category;  // std::random_access_iterator_tag
```

В main.cpp имеется разобранный на паре пример подсчета расстояния с `difference_type`.

Также обсуждалась полезность проверки концептов ваших итераторов с помощью `static_assert` - это позволит понять на этапе компиляции, не забыли ли вы что либо в своем итераторе:

```cpp
// Проверка соответствия концепту std::random_access_iterator
static_assert(std::random_access_iterator<MyRandomAccessIterator<int>>);
static_assert(std::random_access_iterator<MyRandomAccessIterator<double>>);
static_assert(std::random_access_iterator<MyRandomAccessIterator<std::string>>);
```

---
