#include <stdio.h>

void hanoitower(int n, char from, char tmp, char to) {
	printf("\nDisk %d : %c -> %c\n", n, from, to);
	if (n == 1) printf("\t<MOVE 1 : %c -> %c>\n------------------------\n", from, to);
	else {
		printf("\tCALL %d : %c -> %c\n", n - 1, from, tmp);
		hanoitower(n - 1, from, to, tmp);
		printf("\t<MOVE %d : %c -> %c>\n", n, from, to);
		printf("\tCALL %d : %c -> %c\n", n - 1, tmp, to);
		hanoitower(n - 1, tmp, from, to);
	}
}

int main() {
	hanoitower(4, 'A', 'B', 'C');
	return 0;
}