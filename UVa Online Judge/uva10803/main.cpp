#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int N;
struct point
{
    double x,y;
} points[105];
double maps[105][105];
double dis(point p1,point p2)
{
    return sqrt( pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}
int main()
{
    int T;
    cin >> T;
    for(int t = 1 ; t <= T;++t)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                if(i == j)
                    maps[i][j] = 0;
                else
                    maps[i][j] = 1e9;
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> points[i].x;
            cin >> points[i].y;
        }

        for(int i = 0 ; i < N;++i)
        {
            for(int j = i +1 ; j < N;++j)
            {
                if(dis(points[i],points[j])<= 10)
                {
                    //cout << i << "  " << j << endl;
                    maps[i][j] = maps[j][i] = dis(points[i],points[j]);
                }
            }
        }

        for(int k = 0 ; k < N;++k)
        {
            for(int i = 0 ; i < N ; ++i)
            {
                for(int j = 0 ; j < N;++j)
                {

                    maps[i][j] = min(maps[i][j],maps[i][k] + maps[k][j]);
                    //cout << i  << "  " << j << " " << maps[i][j] << endl;
                }
            }
        }
        double maxD = -1;
        int status = 0;
        for(int i = 0 ; i < N  && !status;++i)
        {
            for(int j = 0 ; j < N && !status; ++j)
            {
                if(i!=j)
                {
                    if(maps[i][j] != 1e9)
                    {
                        if(maps[i][j] > maxD)
                        {
                            maxD = maps[i][j];
                        }
                    }
                    else
                    {
                        status = 1;
                    }
                }
            }
        }
        cout << "Case #" << t << ":" <<endl;
        if(status == 1)
        {
            cout << "Send Kurdy" <<endl;
        }
        else
        {
            cout << fixed << setprecision(4) << maxD <<endl;
        }
        cout << endl;
    }
    return 0;
}
