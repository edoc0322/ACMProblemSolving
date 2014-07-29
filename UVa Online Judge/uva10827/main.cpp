#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int maps[300][300];
int copyMap[80][80];
int N;

int findMaxSum(int sx,int sy,int ex,int ey)
{
    int sums = maps[ey][ex];
    if(sx >= 1)
    {
        sums -= maps[ey][sx-1];
    }
    if(sy >= 1)
    {
        sums -= maps[sy-1][ex];
    }
    if(sx >= 1 && sy >= 1)
    {
        sums += maps[sy-1][sx-1];
    }
    return sums;
}

int max2DSum()
{
    for(int i = 0 ; i < 2*N;++i)
    {
        for(int j = 1 ; j < 2*N;++j)
        {
            maps[i][j] += maps[i][j-1];
        }
    }
    for(int i = 0 ; i < 2*N;++i)
    {
        for(int j = 1 ; j < 2*N;++j)
        {
            maps[j][i] += maps[j-1][i];
        }
    }

    int maxI = -2*1e9;
    for(int i = 0 ; i < N;++i)
    {
        for(int j = 0 ; j < N;++j)
        {
            for(int x = j ; x < j+N;++x)
            {
                for(int y = i ; y < i+N;++y)
                {
                    maxI = max(maxI,findMaxSum(j,i,x,y));
                }
            }
        }
    }
    return maxI;
}



int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cin >> maps[i][j];
                maps[i+N][j] = maps[i][j+N] = maps[i+N][j+N] = maps[i][j];
            }
        }
        cout << max2DSum() <<endl;



    }
    return 0;
}
