#include <iostream>
#include <algorithm>
using namespace std;

int maps[105][105];
int N;

int findMaxSum(int sx,int sy,int ex,int ey)
{
    int sums = maps[ey][ex];
    if(sx >= 2)
    {
        sums -= maps[ey][sx-1];
    }
    if(sy >= 2)
    {
        sums -= maps[sy-1][ex];
    }
    if(sx >= 2 && sy >= 2)
    {
        sums += maps[sy-1][sx-1];
    }
    if(sums == 0)
    {
        return (ey-sy+1)*(ex-sx+1);
    }
    return 0;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N;
        for(int i = 1 ; i <= N;++i)
        {
            for(int j = 1 ; j <= N;++j)
            {
                maps[i][j] = 0;
            }
        }
        int B;
        cin >> B;
        int r1,c1,r2,c2;
        for(int i = 0 ; i < B;++i)
        {
            cin >> r1 >> c1 >> r2 >> c2;
            for(int j = r1 ; j <= r2;++j)
            {
                for(int k = c1 ; k <= c2;++k)
                {
                    maps[j][k] = 1;
                }
            }
        }

        for(int i = 1 ; i <= N;++i)
        {
            for(int j = 2 ; j <= N;++j)
            {
                maps[i][j] += maps[i][j-1];
            }
        }

        for(int i = 1 ; i <= N;++i)
        {
            for(int j = 2 ; j <= N;++j)
            {
                maps[j][i] += maps[j-1][i];
            }
        }
        int maxI = -2*1e9;
        for(int i = 1 ; i <= N;++i)
        {
            for(int j = 1 ; j <= N;++j)
            {
                for(int x = j ; x <= N;++x)
                {
                    for(int y = i ; y <= N;++y)
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
