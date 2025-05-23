#include <stdio.h>
#include <setjmp.h>

// Global variable for storing jump context
jmp_buf jump_buffer;

// Global variable for storing sum
unsigned long long sum = 0;

// Recursive function for calculating Fibonacci numbers and their sum
void fibonacci(unsigned long long a, unsigned long long b, int n) {
    // If we reached the required number of terms, perform non-local jump
    if (n == 0) {
        longjmp(jump_buffer, 1);
    }
    
    // Add current number to sum
    sum += a;
    
    // Recursive call for next Fibonacci number
    fibonacci(b, a + b, n - 1);
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to sum: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }
    
    // Set the return point
    if (setjmp(jump_buffer) == 0) {
        // Start calculation with first two Fibonacci numbers (1, 1)
        fibonacci(1, 1, n);
    }
    
    printf("Sum of first %d Fibonacci numbers: %llu\n", n, sum);
    
    return 0;
} 
