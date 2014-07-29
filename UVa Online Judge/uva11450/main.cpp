#include <iostream>
#include <algorithm>
using namespace std;

int M,C;
int num[21][21];
int numSize[21];
int dp[201][21];
int minI;

int findAns(int money, int dep)
{
    //cout << money << "  dpe " << dep <<endl;
    if(money < 0)
    {
        return 99999;
    }
    if(dep == C)
    {
        if(money >= 0 && dp[money][dep] > money)
        {
            dp[money][dep] = money;
        }
        //cout << money << " dp " << dp[money][dep] <<endl;
        return dp[money][dep];
    }
    if(dp[money][dep] != 99999)
    {
        return dp[money][dep];
    }
    int minI2 = 99999;
    for(int i = 0 ; i < numSize[dep];++i)
    {
        int temp = findAns(money-num[dep][i],dep+1);
        if(temp < minI2)
        {
            minI2 = temp;
        }
    }
    dp[money][dep] = minI2;
    return dp[money][dep];

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> M >> C;
        for(int i = 0 ; i < C;++i)
        {
            cin >> numSize[i];
            for(int j = 0 ; j < numSize[i];++j)
            {
                cin >> num[i][j];
            }
        }
        for(int i = 0 ; i <= M;++i)
        {
            for(int j = 0 ; j <= C;++j)
                dp[i][j] = 99999;
        }
        int ans = findAns(M,0);
        if(ans == 99999)
        {
            cout << "no solution" <<endl;
        }
        else
        {
            cout << M-ans <<endl;
        }

    }
    return 0;
}
