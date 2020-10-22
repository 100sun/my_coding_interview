#include <iostream>
using namespace std;

class Rectangle {
private:
	int w;
	int h;
public:
	Rectangle() {
		w = 1;
		h = 1;
	}

	Rectangle(int width, int height) {
		w = width;
		h = height;
	}

	int getW() {
		return w;
	}

	int getH() {
		return h;
	}

	double area() {
		return w * h;
	}

	int perimeter() {
		return (w + h) * 2;
	}
};

int main()
{
	Rectangle r1(10, 20);
	cout << "�簢���� ���α��� = " << r1.getW() << "\n�簢���� ���α��� = " << r1.getH()
		<< "\n=>�簢���� ���� = " << r1.area() << "\n=>�簢���� �ѷ� = " << r1.perimeter() << endl;

	return 0;
}

