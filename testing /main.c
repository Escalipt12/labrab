1. 
#include <stdio.h>
#include <time.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Ne ydalos otrit fail input.txt");
        return 1;
    }

    int day, month, year;
    if (fscanf(file, "%d.%d.%d", &day, &month, &year) != 3) {
        printf("owibka 4tenia dati  iz faila\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    
    time_t now = time(NULL);
    struct tm current_date = *localtime(&now); // текущая дата

    
    struct tm target_date = {0};
    target_date.tm_mday = day;
    target_date.tm_mon = month - 1;  // месяц с 0
    target_date.tm_year = year - 1900; // с 1900 года

    time_t target_time = mktime(&target_date);
    if (target_time == -1) {
        printf("owibka preobrzovania dati\n");
        return 1;
    }

    double diff_seconds = difftime(target_time, now);
    int diff_days = (int)(diff_seconds / (60 * 60 * 24)); 

    printf("kol vo dney do %02d.%02d.%04d: %d\n", day, month, year, diff_days);

    return 0;
}
2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int m;
    int i;
    int j;
    printf("Enter matrix size (m): ");
    scanf("%d", &m);

    
    srand(time(NULL));

    
    int matrix[m][m];
    
    
    printf("Generated matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
4. 
#include <stdio.h>
#include <time.h>

void long_running_operation() {
    
    int i;
    for (i = 0; i < 100000000; i++);
}

int main() {
    clock_t start = clock();
    
    
    long_running_operation();
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Program execution time: %.3f seconds\n", time_taken);
    
    return 0;
}
