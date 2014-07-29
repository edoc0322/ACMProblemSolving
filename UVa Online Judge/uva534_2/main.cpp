#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

double lengths(double x1,double y1,double x2, double y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int INF = 0x06ffffff;


int N;

double maps[201][201];
double px[201];
double py[201];
int main()
{
    int c = 1;
    while(cin >> N)
    {
        if(!N) break;
        for(int i = 0 ;i < N;++i)
        {
            //cout << i << endl;

            cin >> px[i];
            cin >> py[i];
        }
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = INF;
            }
        }

        for(int i = 0 ; i < N;++i)
        {
            for(int j = i+1;j < N;++j)
            {
                maps[i][j] = maps[j][i] = lengths(px[i],py[i],px[j],py[j]);

            }
        }
        for(int i = 0 ; i < N;++i)
        {
            maps[i][i] = 0;
        }
        for(int k = 0 ; k < N;++k)
        {
            for(int i = 0 ; i < N;++i)
            {
                for(int j = 0 ; j < N;++j)
                {
                    //cout << i << " " << j << " " << k <<endl;
                    //cout << maps[i][j]<<" "<< maps[i][k] << " " << maps[k][j]<<endl;
                    maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);
                }
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            for(int j = i+1 ; j < N;++j)
            {
                cout << i<<" "<< j <<" "<< maps[i][j]<<endl;
            }
        }

        cout << "Scenario #"<<c++ <<endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << maps[0][1]<<endl<<endl;;;
    }
    return 0;
}
