#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
public:
    double x, y, z;
   
    void randomPoint(int a, int b)
    {
        //srand(time(NULL));
        x = (double)(a + rand() % (b - a) + 1);
        y = (double)(a + rand() % (b - a) + 1);
        z = (double)(a + rand() % (b - a) + 1);
    }
};

class Gun
{
    Point Position;
    Point P1;
public:
   
    int magazine;
    int bulletsLeft;
    
    void shoot()
    {
        bulletsLeft = magazine;
        srand(time(NULL));
        while (bulletsLeft)
        {
            P1.randomPoint(-10,10);
            //cout << P1.x << " " << P1.y << " " << P1.z << endl;;
            bulletsLeft--;
        }
    }
    void reload()
    {
        bulletsLeft = magazine;
    }

};


int main()
{
    Point P1;
    Gun pewPew;
    
   // cout << P1.x << " " << P1.y << " " << P1.z << endl;
    pewPew.shoot();

}