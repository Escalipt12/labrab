#include <stdio.h>
#include <stdlib.h>

struct humen {
    char name[50];
    char surname[50];
    int birth_year;
};

int main() {
    struct humen original[29];
    struct humen sorted[29];
    FILE *file;
    int i, j;

    file = fopen("input.txt", "r");

    for (i = 0; i < 29; i++) {
        if (fscanf(file, "%s %s %d", original[i].name, original[i].surname, &original[i].birth_year) != 3) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    for (i = 0; i < 29; i++) {
        sorted[i] = original[i];
    }

    for (i = 0; i < 29; i++) {
        for (j = 0; j < 29 - i; j++) {
            if (sorted[j].birth_year > sorted[j + 1].birth_year) {
                struct humen temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    
    printf("\nResult:\n");
    for (i = 1; i < 29; i++) {
        printf("%s %s, %d\n",
               sorted[i].surname,
               sorted[i].name,
               sorted[i].birth_year);
    }

    return 0;
}
