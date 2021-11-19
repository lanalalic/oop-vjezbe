#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
public:
    double x, y, z;
};

class Target 
{
    Point bottomLeft, topRight;
public:

    void targetHit(Point bottomLeft,Point topRight, Point shot)
    {
        if ((shot.x >= bottomLeft.x) && (shot.x <= topRight.x)
            && (shot.y >= bottomLeft.y) && (shot.y <= topRight.y)
            && (shot.z >= bottomLeft.z) && (shot.z <= topRight.z))
            cout << "Target hit!" << endl;
        else
            cout << "Target missed!" << endl;
    }
    
};

int main()
{
    Point bl, tr, shot;
    Target t1;
    bl.x = 0; bl.y = 2; bl.z = 1;
    tr.x = 10; tr.y = 11; tr.z = 9;
    shot.x = 5;
    shot.y = 5;
    shot.z = 5;
    t1.targetHit(bl, tr, shot);
    shot.x = -5;
    shot.y = 5;
    shot.z = 5;
    t1.targetHit(bl, tr, shot);
}

