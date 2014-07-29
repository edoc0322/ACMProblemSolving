#include <iostream>

using namespace std;
int dp[1000001];
int n,m,m10[10];
int main()
{

    while(cin >> n)
    {
        cin >> m;
        for(int i = 0 ; i < m;++i)
        {
            cin >> m10[i];
        }
        for(int i = 0 ; i <=n;++i)
        {
            dp[i] = 0;
        }
        for(int i = 1;i<=n;++i)
        {
            for(int j = 0 ;j <m;++j)
            {
                if(i -m10[j]>=0)
                    if(dp[i-m10[j]]==0)
                    {
                        dp[i] = 1;
                        break;
                    }
            }
        }
        if(dp[n])
        {
            cout <<"Stan wins\n";
        }
        else
        {
            cout <<"Ollie wins\n";
        }
    }
    return 0;
}
