#include <iostream>
#include "Rectangle.h"
#include <cmath>
using namespace std;

int main()
{
	Rectangle rectangle1(8, 6);
	Rectangle rectangle2(2 , 4);

	cout << " �簢��1�� ���α��� = " << rectangle1.getWidth() << endl
		<< " �簢��1�� ���α��� = " << rectangle1.getHeight() << endl
		<< " �簢��1�� ���� = " << rectangle1.Area() << endl
		<< " �簢��1�� �밢�� ���� = " << rectangle1.Diagonal() << endl
		<< " �簢��1�� �ѷ� = " << rectangle1.Perimeter() << endl;
	cout << "\n";
	cout << " �簢��2�� ���α��� = " << rectangle2.getWidth() << endl
		<< " �簢��2�� ���α��� =  " << rectangle2.getHeight() << endl
		<< " �簢��2�� ���� = " << rectangle2.Area() << endl
		<< " �簢��2�� �밢�� ���� = " << rectangle2.Diagonal() << endl
		<< " �簢��2�� �ѷ� = " << rectangle2.Perimeter() << endl;

	system("pause");
	return 0;
}