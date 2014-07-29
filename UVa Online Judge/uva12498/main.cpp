#include <iostream>
#include <string>
#include <algorithm>
#define MAX 99999999
using namespace std;

int r,c;
string maps[50];
int main()
{
    int T;
    cin >> T;
    for(int t = 1 ; t <= T;++t)
    {
        cin >> r >> c;
        for(int i = 0 ; i < r;++i)
        {
            cin >> maps[i];
        }
        int minD = MAX;
        for(int i = 0 ; i < c;++i)
        {
            int dis = 0;
            for(int j = 0 ; j < r;++j)
            {
                if(maps[j][i] == '0')
                {
                    continue;
                }
                else
                {
                    int LD = MAX;
                    int RD = MAX;
                    for(int k = i-1; k >= 0 ;--k)
                    {
                        if(maps[j][k] =='0')
                        {
                            LD = i-k;
                            break;
                        }
                    }
                    for(int k = i+1; k < c ;++k)
                    {
                        if(maps[j][k] == '0')
                        {
                            RD = k-i;
                            break;
                        }
                    }
                    //cout << i << " " << j << " " << LD << " " << RD <<endl;
                    if(LD == MAX && RD == MAX)
                    {
                        dis = MAX;
                        break;
                    }
                    else
                    {
                        dis += min(LD,RD);
                    }
                }
            }
            minD = min(dis,minD);
        }
        cout << "Case " << t << ": " ;
        if(minD == MAX)
        {
            cout << -1 <<endl;
        }
        else
        {
            cout << minD <<endl;
        }
    }
    return 0;
}
