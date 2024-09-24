#include <array>
#include <iostream>

// Пример работы с C-style массивом char
void handleCStyleCharArray(const std::size_t charArraySize) {
  // Выделение памяти через оператор new
  char* charArray = new char[charArraySize];

  std::cout << "Введите элементы массива: ";
  for (int i = 0; i < charArraySize; ++i) {
    scanf(" %c", &charArray[i]); // считываем каждый символ отдельно (избегаем пробелов)
    // Помним про особенности записи в C-style
  }

  printf("Содержимое массива: ");
  for (int i = 0; i < charArraySize; ++i) {
    printf("%c ", charArray[i]);
  }

  // Не забываем освободить память - святое дело
  delete[] charArray;
}

// Пример работы с std::array<int, N>
void handleStdArray() {
  const std::size_t array_size = 5;  // Задаём размер на этапе компиляции

  std::array<int, array_size> intArray{};
  std::cout << "Введите 5 элементов std::array: ";

  for (size_t i = 0; i < array_size; ++i) {
    scanf("%d", &intArray[i]);  // Помним про особенности записи и вывода в C-style
  }

  printf("Содержимое std::array: ");
  for (size_t i = 0; i < array_size; ++i) {
    printf("%d ", intArray[i]);
  }

  // У контейнера память освободится автоматически при выходе из scope
}

int main() {
  std::size_t charArraySize;
  std::cout << "Введите размер C-style массива: ";
  std::cin >> charArraySize;

  // Пример с C-style массивом
  handleCStyleCharArray(charArraySize);

  // Пример с std::array<int, N>
  handleStdArray();
}