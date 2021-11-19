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
};

class Gun
{
    Point shot;
    
public:

    int magazine = 6;
    int bulletsLeft;
    int a = -10, b = 10;
    int numOfTargets = 2;
    int cnt=0;

    int shoot(Point shot, Point bottomLeft, Point topRight)
    {
        bulletsLeft = magazine;
        srand(time(NULL));
        shot.y = (double)(a + rand() % (b - a) + 1);
        while (bulletsLeft)
        {   
            shot.x = (double)(a + rand() % (b - a) + 1);
            shot.z = (double)(a + rand() % (b - a) + 1);
            for (int i = 0; i < numOfTargets; i++)
            {
                if ((shot.x > bottomLeft.x) && (shot.x < topRight.x)
                    && (shot.x > bottomLeft.y) && (shot.x < topRight.y)
                    && (shot.x > bottomLeft.z) && (shot.x < topRight.z))
                    cnt++;
            }
            cout << shot.x << " " << shot.y << " " << shot.z << endl;
            bulletsLeft--;
        }
        return cnt;
    }

};

void randomTarget(Point bottomLeft, Point topRight)
{
    //srand(time(NULL));
    int a = -10, b = 10;
    bottomLeft.x=(double)(a + rand() % (b - a) + 1);
    bottomLeft.y = (double)(a + rand() % (b - a) + 1);
    bottomLeft.z = (double)(a + rand() % (b - a) + 1);
    cout << bottomLeft.x << " " << bottomLeft.y << " " << bottomLeft.z << endl;
   
    topRight.x = (double)(a + rand() % (b - a) + 1) +b;
    topRight.y = (double)(a + rand() % (b - a) + 1) +b;
    topRight.z = (double)(a + rand() % (b - a) + 1) +b;
    cout << topRight.x << " " << topRight.y << " " << topRight.z << endl;

}


int succesfulShots(int numOfTargets, Gun Shooter, Point bottomLeft, Point topRight, Point shot)
{
    int cnt = 0;
    srand(time(NULL));
    for (int i = 0; i < numOfTargets; i++)
    {
        randomTarget(bottomLeft, topRight);
        cnt += Shooter.shoot(shot, bottomLeft, topRight);     
    }
    return cnt;
}

int main()
{
    int n = 2,cnt;
    Point bl,tr, shot;
    bl.x = 0; bl.y = 0; bl.z = 0;
    tr.x = 0; tr.y = 0; tr.z = 0;
    shot.x = 0; shot.y = 0; shot.z = 0;
    
    
    Gun shooter;
    Target T;

    cout << succesfulShots(n, shooter, bl, tr, shot);

    // randomTarget(bl, tr);
}
