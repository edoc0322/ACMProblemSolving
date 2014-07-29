#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

string maps[300];
int sums[300][300];
int counts;

int findSubMax(int sx,int sy,int ex,int ey)
{
    int ans = sums[ey][ex];
    if(sx >= 1)
    {
        ans -= sums[ey][sx-1];
    }
    if(sy >= 1)
    {
        ans -= sums[sy-1][ex];
    }
    if(sx >= 1 && sy >= 1)
    {
        ans += sums[sy-1][sx-1];
    }
    //cout << ans << "    "<< sx << " " << sy << " " << ex << " " << ey <<endl;
    if(ans == (ey-sy+1)*(ex-sx+1))
    {
        //if(ans == 24)
        //{
        //    cout << sx << " " << sy << " " << ex << " " << ey <<endl;
        //}
        return ans;
    }
    else
    {
        return 0;
    }
    //return ans;
}

int max2DSums()
{
    for(int i = 0 ; i < counts;++i)
    {
        for(int j = 1 ; j < counts;++j)
        {
            sums[i][j] += sums[i][j-1];
        }
    }
    for(int i = 0 ; i < counts;++i)
    {
        for(int j = 1 ; j < counts;++j)
        {
            sums[j][i] += sums[j-1][i];
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
    int test;
    cin >> test;
    getchar();
    getchar();
    string temp;
    counts = 0;
    for(int t=  0 ; t < test;++t)
    {
        if(t > 0) cout <<endl;
        cin >> temp;
        maps[0] = temp;
        counts = temp.length();
        for(int i = 1 ; i < counts;++i)
        {
            cin >> temp;
            maps[i] = temp;
        }
        for(int i = 0 ; i < counts;++i)
        {
            for(int j = 0 ; j < counts;++j)
            {
                sums[i][j] = maps[i][j] - '0';
                //cout << sums[i][j];
            }
            //cout <<endl;
        }
        cout << max2DSums() <<endl;
        counts = 0;
        getchar();

    }
    return 0;
}
