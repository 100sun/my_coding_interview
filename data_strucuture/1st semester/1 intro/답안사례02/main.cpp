#include <iostream>
#include "Rectangle.h"
#include <cmath>
using namespace std;

int main()
{
	Rectangle rectangle1(8, 6);
	Rectangle rectangle2(2 , 4);

	cout << " 사각형1의 가로길이 = " << rectangle1.getWidth() << endl
		<< " 사각형1의 세로길이 = " << rectangle1.getHeight() << endl
		<< " 사각형1의 넒이 = " << rectangle1.Area() << endl
		<< " 사각형1의 대각선 길이 = " << rectangle1.Diagonal() << endl
		<< " 사각형1의 둘레 = " << rectangle1.Perimeter() << endl;
	cout << "\n";
	cout << " 사각형2의 가로길이 = " << rectangle2.getWidth() << endl
		<< " 사각형2의 세로길이 =  " << rectangle2.getHeight() << endl
		<< " 사각형2의 넒이 = " << rectangle2.Area() << endl
		<< " 사각형2의 대각선 길이 = " << rectangle2.Diagonal() << endl
		<< " 사각형2의 둘레 = " << rectangle2.Perimeter() << endl;

	system("pause");
	return 0;
}