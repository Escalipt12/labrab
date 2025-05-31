#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <setjmp.h>
#include <limits.h>

jmp_buf _jump_buffer;

unsigned long long sum = 0;

void fibonacci(unsigned long long a, unsigned long long b, int c) {
	if (c == 0) {
		longjmp(_jump_buffer, 1); 
	}

	if (b > ULLONG_MAX - a) {
		printf("Too big. Get lost!\n");
		longjmp(_jump_buffer, 2); 
	}

	sum += a;
	fibonacci(b, a + b, c - 1);
}

int main() {
	int n = 0;

	printf("Enter the number of Fibonacci numbers to sum: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Please enter a positive number.\n");
		return 1;
	}

	int jump_code = setjmp(_jump_buffer);
	if (jump_code == 0) {
		fibonacci(1, 1, n);
	}
	else if (jump_code == 1) {
		printf("Sum of first %d Fibonacci numbers: %llu\n", n, sum);
	}

	return 0;
}
