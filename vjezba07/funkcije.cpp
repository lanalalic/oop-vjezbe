#include "Header.h"

Board::~Board() 
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Board::create() 
{
	matrix = new char* [rows];
	for (int i = 0; i < rows; i++) 
	{
		matrix[i] = new char[columns];
	}
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			if (i == 0 || j == 0 || i == rows - 1 || j == columns - 1) 
			{
				matrix[i][j] = ch;
			}
			else 
			{
				matrix[i][j] = ' ';
			}
		}
	}
}

int Point::xToInt(Point& p) 
{
	return (int)p.x;
}

int Point::yToInt(Point& p) 
{
	return (int)p.y;
}

void Board::drawChar(Point p, char ch) 
{
	matrix[p.xToInt(p)][p.yToInt(p)] = ch;
}

void Board::drawUpLine(Point p1, char ch) 
{
	int x = p1.xToInt(p1);
	int y = p1.yToInt(p1);
	for (int i = x; i > 0; i--) 
	{
		matrix[i][y] = ch;
	}
}

void Board::drawLine(Point p1, Point p2, char ch) 
{
	int startX = p1.xToInt(p1);
	int startY = p1.yToInt(p1);

	int endX = p2.xToInt(p2);
	int endY = p2.yToInt(p2);	
	while (startX != endX || startY != endY) 
	{
		matrix[startX][startY] = ch;
		if (startX > endX)
		{
			startX = endX++;
			if (startY > endY)
			{ 
				startY = endY++;
			}
			else if (endY > startY) 
			{
				startY = endY--;
			}			
		}
		else if (endX > startX) 
		{
			startX = startX++;
			if (startY > endY)
			{
				startY = startY--;
			}	
			else if (endY > startY)
			{ 
				startY = startY++;
			}
		}
		else 
		{
			if (startY > endY)
			{
				startY = startY--;
			}	
			else if (endY > startY)
			{
				startY = startY++;
			}	
		}
		
	}
	matrix[endX][endY] = ch;
}


void Board::display() 
{
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}
