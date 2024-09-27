#include <iostream>

size_t BinarySearch(int target, int* arr, int* indices, size_t arr_size) {
        size_t left = 0;
        size_t right = arr_size - 1;

        while (left <= right) {
            size_t middle = left + (right - left) / 2;
            if (arr[indices[middle]] == target) {
                return middle;
            } else if (arr[indices[middle]] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return -1;
    }

// Функция для сравнения двух элементов массива (по значениям исходного массива)
// Необходима для quick sort
int compare(const void* a, const void* b, void* arr) {
    int* nums = (int*)arr;
    int indexA = *(int*)a;
    int indexB = *(int*)b;
    return nums[indexA] - nums[indexB];
}

// Основная функция для решения задачи
size_t* twoSum(int* nums, size_t numsSize, int target) {
    // Создаем массив индексов
    int* indices = (int*)malloc(numsSize * sizeof(int));
    if (indices == NULL) {
        return NULL; // Ошибка выделения памяти
    }

    // Инициализируем массив индексов
    for (size_t i = 0; i < numsSize; ++i) {
        indices[i] = i;
    }

    // Сортируем массив индексов
    qsort_r(indices, numsSize, sizeof(int), compare, nums);

    // Поиск пары с суммой равной target
    for (size_t i = 0; i < numsSize; ++i) {
        int complement = target - nums[indices[i]];
        size_t complementIndex = BinarySearch(complement, nums, indices, numsSize);

        if (complementIndex != -1 && indices[complementIndex] != indices[i]) {
            // Нашли пару элементов, возвращаем их индексы
            size_t* result = (size_t*)malloc(2 * sizeof(size_t));
            if (result != NULL) {
                result[0] = indices[i];
                result[1] = indices[complementIndex];
            }
            free(indices);
            return result;
        }
    }

    free(indices);
    return NULL; // В случае если не нашли подходящую пару (по условию задачи это невозможно)
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    size_t numsSize = sizeof(nums) / sizeof(nums[0]);

    size_t* result = twoSum(nums, numsSize, target);

    if (result != NULL) {
        printf("Indices found: %zu, %zun", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found");
    }
}
