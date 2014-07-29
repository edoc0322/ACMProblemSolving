#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int maps[101][101];
int counts;

int findSubMax(int sx,int sy,int ex,int ey)
{
    int ans = maps[ey][ex];
    if(sx >= 1)
    {
        ans -= maps[ey][sx-1];
    }
    if(sy >= 1)
    {
        ans -= maps[sy-1][ex];
    }
    if(sx >= 1 && sy >= 1)
    {
        ans += maps[sy-1][sx-1];
    }
    return ans;
}

int max2DSums()
{
    for(int i = 0 ; i < counts;++i)
    {
        for(int j = 1 ; j < counts;++j)
        {
            maps[i][j] += maps[i][j-1];
        }
    }
    for(int i = 0 ; i < counts;++i)
    {
        for(int j = 1 ; j < counts;++j)
        {
            maps[j][i] += maps[j-1][i];
        }
    }
    int maxI = -2 * 1e9;
    for(int i = 0 ; i < counts;++i)
    {
        for(int j = 0 ; j < counts;++j)
        {
            for(int x = j ; x < counts ;++x)
            {
                for(int y = i ; y < counts;++y)
                {
                    maxI =max(maxI,findSubMax(j,i,x,y));
                }
            }
        }
    }
    return maxI;
}

int main()
{
    while(cin >> counts)
    {
        for(int i = 0 ; i < counts;++i)
        {
            for(int j = 0 ; j < counts;++j)
            {
                cin >> maps[i][j];
            }
        }
        cout << max2DSums() <<endl;
    }

    return 0;
}
