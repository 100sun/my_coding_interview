#include <stdio.h>

int count = 0;

int fib(int n) {
	printf("[%d] Fibonacci %d\n", ++count, n);
	if (n == 0) {
		printf("=> %d\n\n", n);
		return 0;
	}
	if (n == 1) {
		printf("=> %d\n", n);
		return 1;
	}
	printf("=> %d + %d\n", n-1, n-2);
	return fib(n - 1) + fib(n - 2);
}

int main() {
	fib(6);
	return 0;
}