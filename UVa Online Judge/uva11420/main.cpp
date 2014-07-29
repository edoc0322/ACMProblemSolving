#include <iostream>
#include <algorithm>
using namespace std;
long long int dp[70][70][2];
long long int findAns(int n,int s,int last)
{

    if(n < 0 || s < 0 || s > n)
    {
        return 0;
    }
    if(s ==0 && s == n)
    {
        return 1;
    }
    if(dp[n][s][last]!= -1)
    {
        return dp[n][s][last];
    }

    if(!last)
        return dp[n][s][0] = findAns(n - 1, s - 1, 0) + findAns(n - 1, s , 1);
    else
        return dp[n][s][1] = findAns(n - 1, s, 1) + findAns(n - 1, s , 0);

}
int main()
{

    int n,s;
    for(int i = 0 ; i < 70;++i)
    {
        for(int j = 0 ; j < 70;++j)
        {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }

    while(cin >> n && cin >> s)
    {
        if(n < 0 && s < 0) break;
        cout << findAns(n,s,0) <<endl;

    }
    return 0;
}
