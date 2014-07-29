#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int maps[105][105];
struct point
{
    double x,y,r;
}points[105];
int K;
double M;
int N;
double dis(point p1 , point p2)
{
    return sqrt( pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
}
int main()
{
    while(cin >> K >> M)
    {

        cin >> points[0].x >> points[0].y >> points[0].r;
        cin >> points[1].x >> points[1].y >> points[1].r;
        cin >> N;
        for(int i = 0 ; i < N+2;++i)
        {
            for(int j = 0 ; j < N+2;++j)
            {
                if(i == j) maps[i][j] = 0;
                else maps[i][j] = 1e9;
            }
        }
        for(int i = 2 ; i < N+2;++i)
        {
            cin >> points[i].x >> points[i].y >> points[i].r;
        }
        for(int i = 0 ; i < N+2;++i)
        {
            for(int j = i +1 ; j < N+2;++j)
            {
                double d = dis(points[i],points[j]);
                if(d - points[i].r - points[j].r <= (double)(K*M))
                {
                    maps[i][j] = maps[j][i] = 1;
                }
            }
        }
        for(int k = 0 ; k < N+2;++k)
            for(int i = 0 ; i < N+2;++i)
            {
                for(int j = 0 ; j < N+2;++j)
                {
                    maps[i][j] = min(maps[i][j] , maps[i][k] + maps[k][j]);
                }
            }
        if(maps[0][1] != 1e9)
        {
            cout << "Larry and Ryan will escape!" <<endl;
        }
        else
        {
            cout << "Larry and Ryan will be eaten to death." <<endl;
        }
    }
    return 0;
}
