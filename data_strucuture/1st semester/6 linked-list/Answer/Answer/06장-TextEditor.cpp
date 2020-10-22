#include "LineEditor.h"

void Usage()
{
	printf("[�޴�����] i-�Է�, d-����, r-����, x-����, e-��ȯ, f-ã��, p-���, l-�����б�, s-����, q-����=> ");
}

int main()
{
	LineEditor editor;
    char command;

    do{
		Usage();
       	command = getchar();
		switch(command) {
			case 'd': editor.DeleteLine(); break;
			case 'i': editor.InsertLine(); break;
			case 'r': editor.ReplaceLine();	break;
			case 'x': editor.DeleteFromIndex(); break;
			case 'e': editor.ExchangeLine(); break;
			case 'f': editor.FindLine(); break;
			case 'l': editor.LoadFile("Test.txt"); break;     
			case 's': editor.StoreFile("Test.txt");	break;
			case 'p': editor.Display();	break;
			case 'q': break;
		}
		fflush(stdin);
    } while(command != 'q');
}
