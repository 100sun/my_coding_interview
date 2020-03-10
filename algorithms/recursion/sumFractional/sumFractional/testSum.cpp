#include <stdio.h>

double sum(double n) {
	printf("sumFractional(%0.2f)\n", n);
	if (n == 1) return 1;
	else if (n < 0 ) return 0;
	else return 1 / n + sum(n - 1);
}

int main() {
	while (true) {
		int n;
		printf("input integer or quit(0) : ");
		scanf_s("%d", &n);
		if (n == 0) break;
		printf("\nresult of sum(%d) => %0.2f\n\n", n, sum(n));
	}
	return 0;
}
