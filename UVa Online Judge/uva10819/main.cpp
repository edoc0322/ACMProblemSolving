#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[105][15000];
int weight[105],value[105];
int N,W;

int findAns(int w,int n)
{
    if(w > W && W <= 1800)
    {
        return -10000;
    }
    if(w > W + 200)
    {
        return -10000;
    }
    if( n == N)
    {
        if(w > W && w <= 2000)
        {
            return -10000;
        }
        return 0;
    }
    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }
    return dp[n][w] = max(findAns(w,n+1),findAns(w+weight[n],n+1)+value[n]);
}
int main()
{
    while(cin >> W && cin >> N)
    {
        for(int i = 0 ; i < N;++i)
        {
            cin >> weight[i] >> value[i];
        }
        memset(dp,-1,sizeof(dp));
        cout << findAns(0,0) <<endl;

    }
    return 0;
}
