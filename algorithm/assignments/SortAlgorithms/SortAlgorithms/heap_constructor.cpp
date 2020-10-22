#include "sort_class.h"

Heap::Heap(int n) {
	S = new int[n + 1];
	if (S == NULL) {
		cout << "No memmory for S[]" << endl;
		exit(1);
	}
}

Heap::~Heap() {
	delete[] S;
}