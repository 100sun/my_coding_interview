#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	Rectangle();
	Rectangle(double, double);

	double getWidth();
	double getHeight();

	void setWidth(double);
	void setHeight(double);

	double Area();
	double Perimeter();
	double Diagonal();


private:
	double width;
	double height;

};
#endif