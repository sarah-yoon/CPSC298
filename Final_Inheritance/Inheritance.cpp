// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape
{
public:
	Shape();
	Shape(double dHeight, double dWidth);
	virtual ~Shape();
	void scale(double dScaleFactor);
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual void displayProperties();

protected:
	double m_dHeight;
	double m_dWidth;
	string m_strType;
};

Shape::Shape() {
	m_dHeight = 0;
	m_dWidth = 0;
	m_strType = "Shape";
}

Shape::~Shape() {
}

Shape::Shape(double dHeight, double dWidth) {
	m_dHeight = dHeight;
	m_dWidth = dWidth;
	m_strType = "Shape";
}

void Shape::displayProperties() {
	cout << "Shape type: " << m_strType << ", height: " << m_dHeight << ", width: " << m_dWidth << endl;
}

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(double dHeight, double dWidth);
	~Rectangle();
	double area();
	double perimeter();
};

Rectangle::Rectangle()
{
	m_dHeight = 0;
	m_dWidth = 0;
	m_strType = "Rectangle";
}

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(double dHeight, double dWidth) {
	m_dHeight = dHeight;
	m_dWidth = dWidth;
	m_strType = "Rectangle";
}

double Rectangle::area() {
	return m_dHeight * m_dWidth;
}

double Rectangle::perimeter() {
	return (m_dHeight * 2) + (m_dWidth * 2);
}

class Circle : public Shape
{
public:
	Circle();
	Circle(double dHeight, double dWidth);
	~Circle();
	double area();
	double perimeter();
};

Circle::Circle()
{
	m_dHeight = 0;
	m_dWidth = 0;
	m_strType = "Circle";
}

Circle::~Circle()
{
}

Circle::Circle(double dHeight, double dWidth) {
	m_dHeight = dHeight;
	m_dWidth = dWidth;
	m_strType = "Circle";
}

double Circle::area() {
	return (1.0/4.0) * M_PI * m_dHeight * m_dHeight;
}

double Circle::perimeter() {
	return m_dHeight * M_PI;
}

int main()
{
	Circle* p_shapeCircle1 = new Circle(2.0, 2.0);
	Circle* p_shapeCircle2 = new Circle(4.0, 4.0);
	Rectangle* p_shapeRectangle1 = new Rectangle(2.0, 3.0);
	Rectangle* p_shapeRectangle2 = new Rectangle(4.0, 6.0);

	Shape* p_shapes[4];

	p_shapes[0] = p_shapeCircle1;
	p_shapes[1] = p_shapeCircle2;
	p_shapes[2] = p_shapeRectangle1;
	p_shapes[3] = p_shapeRectangle2;

	for (int i = 0; i < 4; i++) {
		p_shapes[i]->displayProperties();
		cout << "Area: " << p_shapes[i]->area() << " Perimeter " << p_shapes[i]->perimeter() << endl;
		cout << endl;
	}

}


