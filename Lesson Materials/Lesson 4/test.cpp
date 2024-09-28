// Функция для тестирования. Ее можно добавить перед main() и свободно дополнять.
void RunTests() {
  // Тест 1
  {
    int arrayNew[] = {1, 2, 3, 4};
    int arrayM[] = {5, 6, 7, 8};
    int expectedMixedArray1[] = {1, 5, 3, 7};
    int expectedMixedArray2[] = {5, 2, 7, 4};

    size_t size1 = 4;
    size_t size2 = 4;
    int* mixedArray1 = new int[size1];
    int* mixedArray2 = (int*) std::malloc(size2 * sizeof(int));

    mixArrays(arrayNew, arrayM, mixedArray1, mixedArray2, size1, size2);

    for (size_t i = 0; i < size1; ++i) {
      assert(mixedArray1[i] == expectedMixedArray1[i]);
    }

    for (size_t i = 0; i < size2; ++i) {
      assert(mixedArray2[i] == expectedMixedArray2[i]);
    }

    delete[] mixedArray1;
    std::free(mixedArray2);
  }

  // Тест 2
  {
    int arrayNew[] = {10, 20, 30, 40, 50};
    int arrayM[] = {15, 25, 35, 45};
    int expectedMixedArray1[] = {10, 15, 30, 35, 50};
    int expectedMixedArray2[] = {15, 20, 35, 40};

    size_t size1 = 5;
    size_t size2 = 4;
    int* mixedArray1 = new int[size1];
    int* mixedArray2 = (int*) std::malloc(size2 * sizeof(int));

    mixArrays(arrayNew, arrayM, mixedArray1, mixedArray2, size1, size2);

    for (size_t i = 0; i < size1; ++i) {
      assert(mixedArray1[i] == expectedMixedArray1[i]);
    }

    for (size_t i = 0; i < size2; ++i) {
      assert(mixedArray2[i] == expectedMixedArray2[i]);
    }

    delete[] mixedArray1;
    std::free(mixedArray2);
  }

  // Тест 3
  {
    int arrayNew[] = {4, 8, 12, 16, 20};
    int arrayM[] = {3, 9, 27};
    int expectedMixedArray1[] = {4, 3, 12, 27, 20};
    int expectedMixedArray2[] = {3, 8, 27};

    size_t size1 = 5;
    size_t size2 = 3;
    int* mixedArray1 = new int[size1];
    int* mixedArray2 = (int*) std::malloc(size2 * sizeof(int));

    mixArrays(arrayNew, arrayM, mixedArray1, mixedArray2, size1, size2);

    for (size_t i = 0; i < size1; ++i) {
      assert(mixedArray1[i] == expectedMixedArray1[i]);
    }

    for (size_t i = 0; i < size2; ++i) {
      assert(mixedArray2[i] == expectedMixedArray2[i]);
    }

    delete[] mixedArray1;
    std::free(mixedArray2);
  }

  // Возможно, ваши личные тесты...

  std::cout << "All tests passed!\n";
}
