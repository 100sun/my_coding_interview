#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
private:
	double width;
	double height;
public:
	Rectangle() {};
	Rectangle(double newWidth, double newHeight) {
		width = newWidth; height = newHeight;
	}
	double getWidth() {
		return width;
	}
	double getHeight() {
		return height;
	}
	double area() {
		return width * height;
	}
	double perimeter() {
		return (width + height) * 2;
	}
	double hypotenuse() {
		return sqrt(pow(width, 2) + pow(height, 2));
	}
};

int main() {
	Rectangle rect(4, 8);

	cout << "The width is " << rect.getWidth() << endl;
	cout << "The height is " << rect.getHeight() << endl;
	cout << "The area is " << rect.area() << endl;
	cout << "The perimeter is " << rect.perimeter() << endl;
	cout << "The hypotenuse is " << rect.hypotenuse() << endl;

	system("PAUSE");
	return 0;
}