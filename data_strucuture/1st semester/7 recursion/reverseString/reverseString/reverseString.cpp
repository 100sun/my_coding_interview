#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int length = strlen("Merry Christmas") - 1;

void reverse(const char *alphabet) {
	if (length == -1) return;
	else {
		printf(alphabet[length--]);
		reverse(alphabet);
	}
}

int main() {
	reverse("Merry Christmas");
	return 0;
}