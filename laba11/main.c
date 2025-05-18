#include <stdio.h>
#include "calc.h"

int main() {
    double nums[] = {1.5, -2.3, 4.7, 3.2, 0.8};
    int count = 5;
    
    printf("Numbers: ");
    for(int i = 0; i < count; i++) 
        printf("%.1f ", nums[i]);
    printf("\n");
    
    printf("Sum: %.2f\n", sum(5, nums[0], nums[1], nums[2], nums[3], nums[4]));
    printf("Max: %.2f\n", max(5, nums[0], nums[1], nums[2], nums[3], nums[4]));
    printf("Min: %.2f\n", min(5, nums[0], nums[1], nums[2], nums[3], nums[4]));
    printf("Average: %.2f\n", avg(5, nums[0], nums[1], nums[2], nums[3], nums[4]));
    
    return 0;
} 
