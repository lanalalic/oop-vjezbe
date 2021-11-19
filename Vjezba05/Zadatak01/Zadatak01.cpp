#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
public:
    double x, y, z;
    void setPoint0()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    void randomPoint(int a, int b)
    {
        srand(time(NULL));
        x = (double)(a + rand() % (b - a) + 1);
        y = (double)(a + rand() % (b - a) + 1);
        z = (double)(a + rand() % (b - a) + 1);

    }
    void getPoint()
    {
        cout << "Input coordinates: ";
        cin >> x;
        cin >> y;
        cin >> z;
    }

    double distance2D(Point P1, Point P2)
    {
        return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
    }
    double distance3D(Point P1, Point P2)
    {
        return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2) + pow(P2.z - P1.z, 2));
    }
};


int main()
{
    Point P1, P2;
    
    //P1.randomPoint(10, 50);
    //cout << P1.x << " " << P1.y << " " << P1.z << endl;;
    P1.getPoint();
    P2.getPoint();
   
    cout << "Distance in 2D space is: " << P1.distance2D(P1, P2) << endl;
    cout << "Distance in 3D space is: " << P1.distance3D(P1, P2) << endl;

}