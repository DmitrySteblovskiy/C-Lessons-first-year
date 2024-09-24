#include <cstdio>
#include <cstdlib>
#include <cstring>

// Функция для выделения памяти и заполнения массива
char* allocate_and_fill_array(size_t size) {
  char* array = (char*)malloc(size * sizeof(char));

  if (array == NULL) {
    printf("Ошибка выделения памяти");
    return NULL;
  }

  printf("Введите символы для массива: ");
  for (size_t i = 0; i < size; ++i) {
    scanf(" %c", &array[i]);
  }
  return array;
}

// Функция для копирования данных между массивами
void copy_array(char* dest, const char* src, size_t copySize) {
  memcpy(dest, src, copySize * sizeof(char));
}

// Функция для перераспределения памяти второго массива и дополнительного заполнения
char* reallocate_and_fill_array(char* array, size_t oldSize, size_t newSize) {
  char* temp = (char*)realloc(array, newSize * sizeof(char));

  if (temp == NULL) {
    printf("Ошибка перераспределения памяти");
    free(array); // Освобождаем ранее выделенную память для array
    return NULL;
  }
  array = temp;

  // Заполнение оставшейся части новыми значениями, если новый размер больше старого
  if (newSize > oldSize) {
    printf("Введите дополнительные символы для нового размера массива: ");
    for (size_t i = oldSize; i < newSize; ++i) {
      scanf(" %c", &array[i]);
    }
  }

  return array;
}

// Функция для вывода массива
void print_array(const char* array, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    printf("%c ", array[i]);
  }
}


int main() {
  // Введите размер первого массива
  size_t size1;
  printf("Введите размер первого массива: ");
  scanf("%zd", &size1);

  // Выделение памяти и заполнение первого массива
  char* array1 = allocate_and_fill_array(size1);
  if (array1 == NULL) {
    return 1;
  }


  size_t size2;
  printf("Введите размер второго массива: ");
  scanf("%zd", &size2);

  // Выделение памяти для второго массива
  char* array2 = (char*)malloc(size2 * sizeof(char));

  if (array2 == NULL) {
    printf("Ошибка выделения памяти");
    free(array1); // Освобождаем ранее выделенную память для array1
    return 1;
  }


  // Скопируем данные из первого массива во второй, учитывая минимальный размер
  size_t copySize = (size1 < size2) ? size1 : size2;
  copy_array(array2, array1, copySize);

  // Освобождаем память для первого массива, так как он уже не нужен
  free(array1);

  // Вывод содержимого второго массива после копирования
  printf("Содержимое второго массива после копирования: ");
  print_array(array2, size2);


  // Введите новый размер для перераспределения памяти второго массива
  size_t newSize;
  printf("Введите новый размер второго массива: ");
  scanf("%zd", &newSize);

  // Перераспределение памяти для второго массива и заполнение дополнительных значений
  array2 = reallocate_and_fill_array(array2, size2, newSize);

  if (array2 == NULL) {
    return 1;
  }

  // Вывод содержимого второго массива после перераспределения памяти
  printf("Содержимое второго массива после перераспределения памяти: ");
  print_array(array2, newSize);

  // Освобождаем память, выделенную для второго массива
  free(array2);
}
