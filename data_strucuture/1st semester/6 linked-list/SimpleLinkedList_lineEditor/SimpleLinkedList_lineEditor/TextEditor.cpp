#include "LineEditor.h"

void Usage() {
	printf("[�޴�����] i-�Է�,d-����,r-����,p-���,l-�����б�,s-����,q-����=> ");
}

int main() {
	LineEditor editor;
	while (true) {
		Usage();
		char command = getchar();
		if (command == 'q') break;
		switch (command) {
		case 'd': editor.DeleteLine(); break;
		case 'i': editor.InsertLine(); break;
		case 'r': editor.ReplaceLine(); break;
		case 'l': editor.LoadFile("Test.txt"); break;
		case 's': editor.StoreFile("Test.txt"); break;
		case 'p': editor.Display(); break;
		case 'q': break;
		case '1':	editor.DeleteFromIndex(); break;
		case '2':	editor.FindLine(); break;
		case '3':	editor.ExchangeLine(); break;
		}
		fflush(stdin);
	}
	return 0;
}
