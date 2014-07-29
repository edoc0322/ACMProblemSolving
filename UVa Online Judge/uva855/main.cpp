#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct cor
{
    int x,y;
};

bool cmp(cor c1, cor c2)
{
    if(c1.x < c2.x)
    {
        return true;
    }
    else if(c1.x > c2.x)
    {
        return false;
    }
    else
    {
        return c1.y < c2.y;
    }
}

double dis(cor c1, double x, double y)
{
    return sqrt(pow( ((double)c1.x - x),2 ) + pow((double) ((double)c1.y - y),2 ));
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m,n,e;
        cin >> m >> n >> e;
        int x[e];
        int y[e];
        for(int i = 0 ; i < e;++i)
        {
           cin >> x[i] >> y[i];
        }
        sort(x,x+e);
        sort(y,y+e);
        int mid = ((e %2 ) ? (e/2) : (e/2 - 1) );
        cout << "(Street: " << x[mid] << ", Avenue: " << y[mid] << ")" <<endl;

    }
    return 0;
}
