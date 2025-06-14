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

int main() {
    clock_t start, end;
    double cpu_time_used;
    long i;

    start = clock();  

    
    for (i = 0; i < 100000000; i++) {
        
    }

    end = clock();  

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("vremia raboti programm: %f second\n", cpu_time_used);

    return 0;
}
3.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int size = 3; 
    int attempts = 0;
    int found = 0;
    int i;
    int j;
    
    while (!found) {
        attempts++;
        
        
        int mat1[size][size], sum1 = 0;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                mat1[i][j] = rand() % 10;
                sum1 += mat1[i][j];
            }
        }
        
        int mat2[size][size], sum2 = 0;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                mat2[i][j] = rand() % 10;
                sum2 += mat2[i][j];
            }
        }
        
        
        if (sum1 == sum2) {
            found = 1;
            FILE *out = fopen("output.txt", "w");
            
            fprintf(out, "Matrix 1 (sum = %d):\n", sum1);
            for (i = 0; i < size; i++) {
                for (j = 0; j < size; j++) {
                    fprintf(out, "%d ", mat1[i][j]);
                }
                fprintf(out, "\n");
            }
            
            
            fprintf(out, "\nMatrix 2 (sum = %d):\n", sum2);
            for (i = 0; i < size; i++) {
                for (j = 0; j < size; j++) {
                    fprintf(out, "%d ", mat2[i][j]);
                }
                fprintf(out, "\n");
            }
            
            fclose(out);
            printf("Found matrices s pavnoi sum (%d) after %d\n", sum1, attempts);
        }
    }
    
    return 0;
}
