#pragma once
#include <iostream>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	int xToInt(Point& p);
	int yToInt(Point& p);

};

class Board {
private:
	int rows, columns;
	char ch;
	char** matrix;
public:
	Board(int rows, int columns, char ch = 'o') {
		this->rows = rows;
		this->columns = columns;
		this->ch = ch;
		create();
	}
	~Board();
	void create();
	void drawChar(Point p, char ch);
	void drawUpLine(Point p, char ch);
	void drawLine(Point p1, Point p2, char ch);
	void display();
};