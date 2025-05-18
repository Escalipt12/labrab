#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int year;
    char gender;
    float height;
};

int main() {
    struct Person people[100];
    int n = 0;
    FILE *f;
    
    printf("Enter number of people: ");
    scanf("%d", &n);
    
    f = fopen("people.txt", "w");
    
    for(int i = 0; i < n; i++) {
        printf("\nPerson %d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]s", people[i].name);
        printf("Birth year: ");
        scanf("%d", &people[i].year);
        printf("Gender (M/F): ");
        scanf(" %c", &people[i].gender);
        printf("Height (in meters): ");
        scanf("%f", &people[i].height);
        
        fprintf(f, "%s\n%d\n%c\n%.2f\n", 
            people[i].name, people[i].year, 
            people[i].gender, people[i].height);
    }
    fclose(f);
    
    printf("\nSort by:\n");
    printf("1 - name\n");
    printf("2 - year\n");
    printf("3 - gender\n");
    printf("4 - height\n");
    
    int choice;
    scanf("%d", &choice);
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            int swap = 0;
            
            if(choice == 1) 
                swap = strcmp(people[j].name, people[j+1].name) > 0;
            else if(choice == 2) 
                swap = people[j].year > people[j+1].year;
            else if(choice == 3) 
                swap = people[j].gender > people[j+1].gender;
            else if(choice == 4) 
                swap = people[j].height > people[j+1].height;
                
            if(swap) {
                struct Person temp = people[j];
                people[j] = people[j+1];
                people[j+1] = temp;
            }
        }
    }
    
    printf("\nSorted list:\n");
    for(int i = 0; i < n; i++) {
        printf("%s - %d year, gender: %c, height: %.2f m\n", 
            people[i].name, people[i].year, 
            people[i].gender, people[i].height);
    }
    
    return 0;
}
