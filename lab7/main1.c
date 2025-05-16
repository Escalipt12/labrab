#include <stdio.h>

struct humen {
    char name[50];
    char surname[50];
    int birth_year;
};

int main() {
    struct humen original[4];
    struct humen sorted[4];
    int i,j;
    
    printf("Vvedite 4 people:\n");
    
	for(i = 0; i < 4; i++) {
        printf("\nPeople #%d\n", i+1);
        printf("Name: ");
        scanf("%s", original[i].name);
        printf("Surname: ");
        scanf("%s", original[i].surname);
        printf("Year of birth: ");
        scanf("%d", &original[i].birth_year);
    }
    
    for(i = 0; i < 4; i++) {
        sorted[i] = original[i];
    }
    

	for(i = 0; i < 3; i++) {
        for(j = 0; j < 3 - i; j++) {
            if(sorted[j].birth_year > sorted[j+1].birth_year) {
                struct humen temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;
            }
        }
    }
    
    printf("\nResult:\n");
    for(i = 0; i < 4; i++) {
        printf("%s %s, %d\n", 
              sorted[i].surname,
              sorted[i].name,
              sorted[i].birth_year);
    }
    
    return 0;
}
