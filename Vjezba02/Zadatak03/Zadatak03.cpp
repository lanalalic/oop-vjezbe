#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Circle {

	int r, xs, ys;
	void circle_input();
};

struct Rectangle {

	int x1, y1, x2, y2;
	void rectangle_input();
};

void circle_input(Circle& c)
{
	cout << "Radius: " << endl;
	cin >> c.r;
	cout << "Centre coordinate x: " << endl;
	cin >> c.xs;
	cout << "Centre coordinate y: " << endl;
	cin >> c.ys;
}

void rectangle_input(Rectangle* r, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "x1: " << endl;
		cin >> r[i].x1;
		cout << "y1: " << endl;
		cin >> r[i].y1;
		cout << "x2: " << endl;
		cin >> r[i].x2;
		cout << "y2: " << endl;
		cin >> r[i].y2;
	}

}

int intersect(Circle* c, Rectangle* r, int n)
{
	int diag1, diag2, min, max, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		diag1 = sqrt(pow((r[i].x1 - c->xs), 2) + (pow((r[i].y1 - c->ys), 2)));
		diag2 = sqrt(pow((r[i].x2 - c->xs), 2) + (pow((r[i].y2 - c->ys), 2)));
		if (diag1 > diag2)
		{

			max = diag1;
			min = diag2;
		}
		else
		{
			max = diag2;
			min = diag1;
		}
		if (min <= c->r && max >= c->r)
			cnt++;
	}
	return cnt;

}


int main()
{
	Circle c;
	int n;
	cout << "Number of rectangles?" << endl;
	cin >> n;
	Rectangle* r = new Rectangle[n];

	circle_input(c);
	//cout << c.r << c.xs << c.ys;
	cout << "Rectangles: " << endl;
	rectangle_input(r, n);
	int cnt = intersect(&c, r, n);
	cout << "Number of rectangles intersecting with circle:" << cnt << endl;
	delete[] r;
}
