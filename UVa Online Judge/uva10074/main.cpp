#include <iostream>
#include <algorithm>
using namespace std;

int maps[102][102];
int M,N;

int findMaxSum(int sx,int sy,int ex,int ey)
{
    int sums = maps[ey][ex];
    if(sx >= 1)
    {
        sums -= maps[ey][sx-1];
    }
    if(sy >=1)
    {
        sums -= maps[sy-1][ex];
    }
    if(sx >= 1 && sy >= 1)
    {
        sums += maps[sy-1][sx-1];
    }
    if(sums == 0)
    {
        return (ex-sx+1) * (ey-sy+1);
    }
    else
    {
        return 0;
    }
}
int main()
{
    while(cin >> M && cin >> N)
    {
        if(!M &&!N) break;
        for(int i = 0 ; i < M;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cin >> maps[i][j];
            }
        }

        for(int i = 0 ; i < M;++i)
        {
            for(int j = 1 ; j < N;++j)
            {
                maps[i][j] += maps[i][j-1];
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 1 ; j < M;++j)
            {
                maps[j][i] += maps[j-1][i];
            }
        }
        int maxI = -2*1e9;
        for(int i = 0 ; i < M;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                for(int y = i; y < M;++y)
                {
                    for(int x = j ; x < N;++x)
                    {
                        maxI = max(maxI,findMaxSum(j,i,x,y));
                    }
                }
            }
        }
        cout << maxI <<endl;
    }

    return 0;
}
