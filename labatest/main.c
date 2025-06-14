#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Функция для создания матрицы
int** create_matrix(int rows, int cols) {
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Функция для освобождения памяти матрицы
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для заполнения матрицы случайными числами
void fill_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // случайные числа от 0 до 99
        }
    }
}

// Функция для записи матрицы в файл
void write_matrix(FILE* file, int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

// Функция для чтения матрицы из файла
int** read_matrix(FILE* file, int rows, int cols) {
    int** matrix = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    return matrix;
}

// Функция для умножения матриц
int** multiply_matrices(int** matrix1, int** matrix2, int rows1, int cols1, int cols2) {
    int** result = create_matrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Функция для сложения матриц
int** add_matrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Функция для поиска номера минимального элемента в матрице
void find_min_element(int** matrix, int rows, int cols, int* min_row, int* min_col) {
    int min_val = INT_MAX;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
                *min_row = i;
                *min_col = j;
            }
        }
    }
}

// Функция для подсчета нечетных чисел в матрице
int count_odd_numbers(int** matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 != 0) {
                count++;
            }
        }
    }
    return count;
}

// Функция для проверки, есть ли в матрице строка или столбец с одинаковыми числами
int has_uniform_row_or_col(int** matrix, int rows, int cols) {
    // Проверка строк
    for (int i = 0; i < rows; i++) {
        int first = matrix[i][0];
        int uniform = 1;
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] != first) {
                uniform = 0;
                break;
            }
        }
        if (uniform) {
            return 1;
        }
    }

    // Проверка столбцов
    for (int j = 0; j < cols; j++) {
        int first = matrix[0][j];
        int uniform = 1;
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] != first) {
                uniform = 0;
                break;
            }
        }
        if (uniform) {
            return 1;
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));
    clock_t start_time = clock();

    int rows1, cols1, rows2, cols2;

    printf("Введите количество строк и столбцов для первой матрицы: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Введите количество строк и столбцов для второй матрицы: ");
    scanf("%d %d", &rows2, &cols2);

    // Проверка на возможность умножения и сложения
    if (cols1 != rows2) {
        printf("Ошибка: Умножение матриц невозможно, так как количество столбцов первой матрицы не равно количеству строк второй матрицы.\n");
        return 1;
    }
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Ошибка: Сложение матриц невозможно, так как размеры матриц не совпадают.\n");
        return 1;
    }

    // Создание и заполнение матриц
    int** matrix1 = create_matrix(rows1, cols1);
    int** matrix2 = create_matrix(rows2, cols2);
    fill_matrix(matrix1, rows1, cols1);
    fill_matrix(matrix2, rows2, cols2);

    // Запись матриц в файл input.txt
    FILE* input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        printf("Ошибка при открытии файла input.txt\n");
        return 1;
    }
    fprintf(input_file, "%d %d\n", rows1, cols1);
    write_matrix(input_file, matrix1, rows1, cols1);
    fprintf(input_file, "%d %d\n", rows2, cols2);
    write_matrix(input_file, matrix2, rows2, cols2);
    fclose(input_file);

    // Очистка массивов
    free_matrix(matrix1, rows1);
    free_matrix(matrix2, rows2);

    // Чтение матриц из файла input.txt
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Ошибка при открытии файла input.txt\n");
        return 1;
    }
    fscanf(input_file, "%d %d", &rows1, &cols1);
    matrix1 = read_matrix(input_file, rows1, cols1);
    fscanf(input_file, "%d %d", &rows2, &cols2);
    matrix2 = read_matrix(input_file, rows2, cols2);
    fclose(input_file);

    // Умножение матриц
    int** product = multiply_matrices(matrix1, matrix2, rows1, cols1, cols2);

    // Сложение матриц
    int** sum = add_matrices(matrix1, matrix2, rows1, cols1);

    // Запись результатов в файл output.txt
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Ошибка при открытии файла output.txt\n");
        return 1;
    }
    fprintf(output_file, "Результат умножения матриц:\n");
    write_matrix(output_file, product, rows1, cols2);
    fprintf(output_file, "Результат сложения матриц:\n");
    write_matrix(output_file, sum, rows1, cols1);
    fclose(output_file);

    // Поиск номера минимального элемента в матрице1
    int min_row, min_col;
    find_min_element(matrix1, rows1, cols1, &min_row, &min_col);
    printf("Номер минимального элемента в матрице1: (%d, %d)\n", min_row, min_col);

    // Подсчет нечетных чисел в матрице1
    int odd_count = count_odd_numbers(matrix1, rows1, cols1);
    printf("Количество нечетных чисел в матрице1: %d\n", odd_count);

    // Проверка на наличие строки или столбца с одинаковыми числами
    if (has_uniform_row_or_col(matrix1, rows1, cols1)) {
        printf("Матрица1 содержит строку или столбец с одинаковыми числами.\n");
    } else {
        printf("Матрица1 не содержит строку или столбец с одинаковыми числами.\n");
    }

    // Освобождение памяти
    free_matrix(matrix1, rows1);
    free_matrix(matrix2, rows2);
    free_matrix(product, rows1);
    free_matrix(sum, rows1);

    // Замер времени работы программы
    clock_t end_time = clock();
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Время работы программы: %.6f секунд\n", time_spent);

    return 0;
}
