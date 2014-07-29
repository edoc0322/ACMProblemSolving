#include <iostream>
#include <algorithm>
using namespace std;
int m,n,t;
int dp[10002];
int w[2];
int main()
{

    while((cin >> m) && (cin >> n ) && (cin >> t))
    {

        for(int j = 0 ; j <= t;++j)
        {
                dp[j] = -1;
        }
        dp[0] = 0;
        w[0] = m;
        w[1] = n;
        for(int i = 0 ;i<2;++i)
        {
            for(int j = 0 ; j <= t;++j)
            {
                if(j >= w[i] && dp[j-w[i]] != -1)
                    dp[j] = max(dp[j] , dp[j-w[i]]+1);
            }
        }
        if(dp[t] != -1)
        {
            cout << dp[t]<<endl;
        }
        else
        {
            int maxI = t;
            int d = 0;
            while(dp[maxI]==-1)
            {
                d++;
                maxI--;
            }
            cout << dp[maxI] <<" " << d <<endl;
        }


    }
    return 0;
}
