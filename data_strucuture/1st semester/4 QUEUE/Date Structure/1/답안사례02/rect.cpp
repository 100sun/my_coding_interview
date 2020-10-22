#include <iostream>
#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle()
{
	width = 1;
	height = 1;
}

Rectangle::Rectangle(double inputWidth, double inputHeight)
{
	width = inputWidth;
	height = inputHeight;
}

double Rectangle::getWidth()
{
	return width;
}

double Rectangle::getHeight()
{
	return height;
}

void Rectangle::setWidth(double inputWidth)
{
	width = inputWidth;
}

void Rectangle::setHeight(double inputHeight)
{
	height = inputHeight;
}

double Rectangle::Area()
{
	return width * height;
}

double Rectangle::Perimeter()
{
	return (width + height) * 2;
}
double Rectangle::Diagonal()
{
	
	return sqrt(width*width + height * height);
}