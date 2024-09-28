# Операторы new и delete в C++

## Описание операторов new и delete

Операторы `new` и `delete` используются в языке C++ для `динамического` выделения и освобождения памяти. Эти операторы позволяют управлять памятью во время выполнения программы.

### Оператор new

Оператор `new` используется для выделения памяти в куче (heap) для переменных или массивов. Он возвращает `указатель на выделенную область памяти`. 

### Оператор delete

Оператор `delete` используется для освобождения памяти, выделенной с помощью оператора `new`. Он `предотвращает утечки памяти,` возвращая память обратно в систему.

## Примеры использования

### Пример 1: Выделение памяти под переменную

```
int main() {
    // Выделение памяти для переменной типа int
    int* pNumber = new int; // Внутри оператора new выделяется память в куче

    // Присваивание значения
    *pNumber = 42;

    // Использование выделенной памяти
    std::cout << "Значение переменной: " << *pNumber << '\n';

    // Освобождение памяти
    delete pNumber; // Внутри оператора delete память освобождается и возвращается системе
    pNumber = nullptr; // Обнуление указателя для предотвращения висячего указателя
}
```

### Пример 2: Выделение памяти под массив

```
int main() {
    // Выделение памяти для массива из 5 целых чисел
    int* pArray = new int[5]; // Внутри оператора new выделяется блок памяти для массива

    // Присваивание значений элементам массива
    for (size_t i = 0; i < 5; ++i) {
        pArray[i] = i * 2;
    }

    // Использование выделенной памяти
    std::cout << "Элементы массива: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << pArray[i] << " ";
    }

    // Освобождение памяти
    delete[] pArray; // Используем delete[], чтобы освободить память для массива
    pArray = nullptr; // Обнуление указателя для предотвращения висячего указателя
}
```

## Что происходит внутри new и delete

### Оператор new

1. **Выделение памяти**: Когда вызывается оператор `new`, компилятор запрашивает у операционной системы необходимое количество памяти в куче.
2. **Возвращение указателя**: Если выделение памяти успешно, оператор `new` возвращает указатель на начало выделенной области памяти. Если выделение не удается (например, из-за нехватки памяти), вызывается исключение `std::bad_alloc`.

### Оператор delete

1. **Освобождение памяти**: Когда вызывается оператор `delete`, он передает указатель на выделенную область памяти обратно системе.
2. **Возвращение памяти**: Система освобождает память, делая ее доступной для будущих запросов на выделение.


# Управление памятью в C и C++ с использованием malloc, calloc, realloc и free

## 1. Описание операторов malloc и free

### Оператор malloc

Оператор `malloc` (memory allocation) используется для динамического выделения памяти в C (иногда и в плюсах). Он выделяет заданное количество байт и возвращает указатель на начало выделенной области памяти. Если выделение памяти не удается, `malloc` возвращает `NULL`.

### Оператор free

Оператор `free` используется для освобождения памяти, выделенной ранее с помощью `malloc` или других функций для выделения памяти. Освобождение памяти важно для предотвращения утечек памяти.

### Пример 1: Выделение памяти под переменную и массив с использованием malloc и free

```
int main() {
    // Выделение памяти для целого числа
    int *pNumber = (int *)malloc(sizeof(int)); // Внутри malloc запрашивается указанный размер памяти
    if (pNumber == NULL) {
        perror("Не удалось выделить память");  // Типичная команда для вывода текста ошибок в C (но не в плюсах!)
        return EXIT_FAILURE;
    }

    // Присваивание значения
    *pNumber = 42;
    printf("Значение переменной: %d\n", *pNumber);

    // Освобождение памяти
    free(pNumber); // free освобождает память, делая её доступной для других нужд
    pNumber = NULL; // Обнуление указателя

    // Выделение памяти для массива из 5 элементов типа int
    int *pArray = (int *)malloc(5 * sizeof(int)); // Запрос памяти для массива из 5 int
    if (pArray == NULL) {
        perror("Не удалось выделить память");
        return EXIT_FAILURE;
    }

    // Присваивание значений элементам массива
    for (size_t i = 0; i < 5; i++) {
        pArray[i] = i * 2;
    }

    // Использование массива
    printf("Элементы массива: ");
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", pArray[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(pArray);
    pArray = NULL; // Обнуление указателя

    return 0;
}
```

### Что происходит внутри операторов malloc и free

- **malloc**: Операционная система выделяет непрерывный блок памяти, размер которого соответствует указанному количеству байт, и возвращает указатель на этот блок. В случае успешного выделения памяти указатель указывает на начало блока, в противном случае возвращается `NULL`.
  
- **free**: Возвращает ранее выделенную память обратно системе, делая её доступной для дальнейшего использования. При этом содержимое памяти не изменяется, но доступ к ней уже недействителен.

## 2. Об операторах calloc и realloc

### Оператор calloc

Оператор `calloc` (contiguous allocation) также выделяет память, как и `malloc`, но с двумя ключевыми отличиями:
1. Выделяет память для массива и инициализирует все элементы нулями.
2. Принимает два параметра: количество элементов и размер каждого элемента.

### Оператор realloc

Оператор `realloc` используется для изменения размера ранее выделенного блока памяти. Он может увеличить или уменьшить размер блока. Если новый размер больше, дополнительно выделенная память не инициализируется.

### Пример 2: Использование calloc и realloc для работы с массивом

```
int main() {
    // Выделение памяти для массива из 5 элементов типа int с инициализацией нулями
    int *pArray = (int *)calloc(5, sizeof(int)); // Запрос памяти для массива из 5 int
    if (pArray == NULL) {
        perror("Не удалось выделить память");
        return EXIT_FAILURE;
    }

    // Использование массива
    printf("Элементы массива после вызова calloc: ");
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", pArray[i]);
    }
    printf("\n");

    // Изменение размера массива до 10 элементов
    int *pNewArray = (int *)realloc(pArray, 10 * sizeof(int)); // Изменение размера блока памяти
    if (pNewArray == NULL) {
        perror("Не удалось перераспределить память");
        free(pArray); // Освобождение памяти при сбое
        return EXIT_FAILURE;
    }
    pArray = pNewArray;

    // Присваивание новых значений элементам массива
    for (size_t i = 5; i < 10; i++) {
        pArray[i] = i * 2;
    }

    // Использование нового размера массива
    printf("Элементы массива после вызова realloc: ");
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", pArray[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(pArray);
    pArray = NULL; // Обнуление указателя

    return 0;
}
```

### Что происходит внутри calloc и realloc

- **calloc**: Выполняет аналогичные действия, что и `malloc`, но дополнительно инициализирует выделенную память нулями. При этом операционная система может использовать специализированные оптимизированные методы для быстрого обнуления.
  
- **realloc**: При увеличении размера операционная система пытается расширить текущий блок, если это возможно. Если текущий блок не может быть расширен, выделяется новый блок данного размера, копируются данные из старого блока и старый блок освобождается. Если новый размер меньше, содержимое обрезается до нового размера.

Таким образом, `calloc` удобен для инициализации массива, а `realloc` – для гибкого управления размером динамических структур данных в процессе выполнения программы.
```