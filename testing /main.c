
1.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>

int main() {
	setlocale(0, "rus"); // Устанавливаем русскую локаль, чтобы вывод был корректным на русском языке

	int vector_size = {}; // Объявляем переменную для размера вектора (кол-ва случайных чисел)

	printf("Введите размер вектора N: "); // Просим пользователя ввести размер
	scanf_s("%d", &vector_size); // Считываем введённое значение

	if (vector_size <= 0) { // Проверяем, чтобы размер был положительным числом
		printf("Некорректное значение N.\n");
		return 1; // Завершаем программу с кодом ошибки
	}

	FILE* file = fopen("input.txt", "w"); // Пытаемся создать файл для записи
	if (file == NULL) { // Если файл не удалось открыть
		printf("Не удалось создать файл.\n");
		return 1;
	}

	srand(static_cast<unsigned int>(time(NULL))); // Инициализируем генератор случайных чисел текущим временем

	for (int i = 0; i < vector_size; ++i) { // Цикл по количеству чисел
		int random_number = rand() % 100; // Генерируем случайное число от 0 до 99
		fprintf(file, "%d ", random_number); // Записываем его в файл с пробелом
	}

	fclose(file); // Закрываем файл после записи
	return 0; // Успешное завершение программы
}


2. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "rus"); // Устанавливаем русскую локаль для корректного вывода

    int vector_size = 0; // Объявляем переменную для размера вектора

    printf("Введите размер вектора N: ");
    scanf_s("%d", &vector_size);

    if (vector_size <= 0) {
        printf("Некорректное значение N.\n");
        return 1;
    }

    // Выделяем память под массив случайных чисел
    int* numbers = (int*)malloc(vector_size * sizeof(int));
    if (numbers == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    srand((unsigned int)time(NULL)); // Инициализируем генератор случайных чисел

    // Заполняем массив случайными числами
    for (int i = 0; i < vector_size; ++i) {
        numbers[i] = rand() % 100; // от 0 до 99
    }

    // Открываем файл для записи
    FILE* file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Не удалось создать файл.\n");
        free(numbers); // Освобождаем память
        return 1;
    }

    // Записываем массив в файл
    for (int i = 0; i < vector_size; ++i) {
        fprintf(file, "%d ", numbers[i]);
    }

    fclose(file); // Закрываем файл

    // "Очищаем" массив: зануляем все элементы
    for (int i = 0; i < vector_size; ++i) {
        numbers[i] = 0;
    }

    free(numbers); // Освобождаем память, массив удаляется из кучи

    return 0; // Завершение программы
}


3.1 + 4

#define _CRT_SECURE_NO_WARNINGS // Отключаем предупреждение компилятора о небезопасных функциях (fscanf, fopen и т.п.)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // для setlocale

int main() {
    setlocale(0, "rus"); // Устанавливаем русскую локализацию для корректного отображения русского текста в консоли

    // Открываем файл input.txt для чтения
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) { // Проверяем, удалось ли открыть файл
        printf("Не удалось открыть input.txt\n");
        return 1; // Завершаем программу с кодом ошибки
    }

    // Открываем файл output.txt для записи результата
    FILE* output = fopen("output.txt", "w");
    if (output == NULL) { // Проверяем, удалось ли создать файл
        printf("Не удалось создать output.txt\n");
        fclose(input); // Закрываем input перед выходом
        return 1;
    }

    int number; // Переменная для хранения текущего считанного числа

    // Считываем числа из input.txt по одному до конца файла
    while (fscanf(input, "%d", &number) == 1) {
        // Если число делится и на 5, и на 7
        if (number % 5 == 0 && number % 7 == 0) {
            fprintf(output, "ПЯТЬСЕМЬ ");
        }
        // Если только на 5
        else if (number % 5 == 0) {
            fprintf(output, "ПЯТЬ ");
        }
        // Если только на 7
        else if (number % 7 == 0) {
            fprintf(output, "СЕМЬ ");
        }
        // Если не делится ни на 5, ни на 7 — пишем число как есть
        else {
            fprintf(output, "%d ", number);
        }
    }

    fclose(input);  // Закрываем входной файл
    fclose(output); // Закрываем выходной файл

    return 0; // Успешное завершение программы
}


5.2 + 6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <windows.h> // Для Sleep

#define MAX_NUMBERS 1000

int main() {
    setlocale(LC_ALL, "rus");

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть input.txt\n");
        return 1;
    }

    int numbers[MAX_NUMBERS];
    int count = 0;

    // Чтение чисел из файла
    while (fscanf(file, "%d", &numbers[count]) == 1 && count < MAX_NUMBERS) {
        count++;
    }
    fclose(file);

    // Находим ближайший квадрат
    int N = (int)sqrt(count);
    int total = N * N;

    if (total == 0) {
        printf("Недостаточно данных для квадратной матрицы.\n");
        return 1;
    }

    // Выделяем память под матрицу
    int** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i) {
        matrix[i] = (int*)malloc(N * sizeof(int));
    }

    // Заполняем матрицу
    int index = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            matrix[i][j] = numbers[index++];

    // Вывод матрицы и сумм строк
    printf("Матрица %dx%d:\n", N, N);
    for (int i = 0; i < N; ++i) {
        int row_sum = 0;
        for (int j = 0; j < N; ++j) {
            printf("%4d ", matrix[i][j]);
            row_sum += matrix[i][j];
        }
        printf("| Сумма строки: %d\n", row_sum);
        Sleep(500); // пауза 500 мс между строками
    }

    // Пауза перед выводом столбцов
    Sleep(1000);
    printf("\nСуммы по столбцам:\n");

    for (int j = 0; j < N; ++j) {
        int col_sum = 0;
        for (int i = 0; i < N; ++i) {
            col_sum += matrix[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, col_sum);
        Sleep(300); // пауза 300 мс между столбцами
    }

    // Освобождаем память
    for (int i = 0; i < N; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}


7.

#define _CRT_SECURE_NO_WARNINGS // чтобы компилятор не ругался на старые функции типа fscanf
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <windows.h>  // Sleep()
#include <time.h>     // clock()

#define MAX_NUMBERS 1000 // максимально возможное количество чисел в файле

int main() {
    setlocale(LC_ALL, "rus"); // чтобы консоль понимала русский текст

    clock_t start_time = clock(); // замер начала выполнения

    // открываем input.txt для чтения
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть input.txt\n");
        return 1;
    }

    // считываем числа в массив
    int numbers[MAX_NUMBERS];
    int count = 0;
    while (fscanf(file, "%d", &numbers[count]) == 1 && count < MAX_NUMBERS) {
        count++;
    }
    fclose(file); // закрываем файл после чтения

    // считаем размер стороны квадратной матрицы
    int N = (int)sqrt(count);
    int total = N * N;

    // если не хватает чисел — выходим
    if (total == 0) {
        printf("Недостаточно данных для квадратной матрицы.\n");
        return 1;
    }

    // создаём динамическую матрицу NxN
    int** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i) {
        matrix[i] = (int*)malloc(N * sizeof(int));
    }

    // заполняем матрицу числами из массива
    int index = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            matrix[i][j] = numbers[index++];

    // выводим матрицу и считаем суммы строк
    printf("Матрица %dx%d:\n", N, N);
    for (int i = 0; i < N; ++i) {
        int row_sum = 0;
        for (int j = 0; j < N; ++j) {
            printf("%4d ", matrix[i][j]); // выводим элемент
            row_sum += matrix[i][j];     // суммируем строку
        }
        printf("| Сумма строки: %d\n", row_sum);
        Sleep(300); // задержка после каждой строки
    }

    Sleep(500); // пауза перед столбцами

    // считаем и выводим суммы по столбцам
    printf("\nСуммы по столбцам:\n");
    for (int j = 0; j < N; ++j) {
        int col_sum = 0;
        for (int i = 0; i < N; ++i) {
            col_sum += matrix[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, col_sum);
        Sleep(200); //  пауза после каждой суммы столбца
    }

    // освобождаем память, которую выделяли под матрицу
    for (int i = 0; i < N; ++i)
        free(matrix[i]);
    free(matrix);

    // финальный замер времени и вывод
    clock_t end_time = clock();
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000; // перевод в миллисекунды
    printf("\nВремя выполнения программы: %.2f мс\n", duration);

    Sleep(700); // небольшая задержка перед завершением
    return 0;
}
