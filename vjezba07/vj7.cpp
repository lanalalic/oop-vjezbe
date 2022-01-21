#include "Header.h"
#define N 10
#define M 20

int main() {
	Point p1(2, 2), p2(8, 8), p3(8, 2), p4(8, 16), p5(7,17);
	Board b(N, M);
	
	b.drawLine(p1, p2, 'x');
	b.drawLine(p3, p4, 'x');
	b.drawUpLine(p5, '*');
	b.display();
}


