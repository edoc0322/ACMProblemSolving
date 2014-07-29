#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

double pi;

int main()
{
    pi = 2 * asin(1);
    double s,a;
    double ang;
    string d;
    while(cin >> s && cin >> a && cin >> d)
    {
        if(a > 180)
        {
            a= 360 - a;
        }
        if(d == "min")
        {
            ang = a / 60;
        }
        else
        {
            ang = a;
        }
        cout << fixed<<setprecision(6)<<2*pi*(s+6440)*ang/360 << " " << (s+6440)*sin(ang*pi/180/2)*2 << endl;
    }
    return 0;
}
