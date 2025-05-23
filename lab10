#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIND_MAX(arr, size, max) \
    max = arr[0]; \
    for (int i = 1; i < size; i++) { \
        if (arr[i] > max) { \
            max = arr[i]; \
        } \
    }

int main() {
    long long numbers[100];
    int count = 0;
    char input[1000];

    printf("Введите числа через пробел: ");
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, " ");
    while (token != NULL && count < 100) {
        numbers[count] = strtoll(token, NULL, 10);
        count++;
        token = strtok(NULL, " ");
    }

    if (count == 0) {
        printf("Вы не ввели числа.\n");
        return 1;
    }

    long long max_num;
    FIND_MAX(numbers, count, max_num);

    long long sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    double average = (double)sum / count;

    printf("Максимальное число: %lld\n", max_num);
    printf("Среднее арифметическое: %.2f\n", average);

    return 0;
}
