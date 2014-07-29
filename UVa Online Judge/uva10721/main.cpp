#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N,K,M;
long long int dp[60][60];
long long int findAns()
{
    for(int m = 2 ; m <= K;++m)
    {
        for(int j = m ; j <= N;++j)
        {
            for(int k = 1 ; k <= M  ;++k)
            {
                if(j - k > 0)
                    dp[m][j] += dp[m-1][j-k];
            }
        }

    }
    return dp[K][N];
}

int main()
{
    while(cin >> N && cin >> K && cin >> M)
    {
        for(int i = 0 ; i < 60;++i)
        {
            for(int j = 0 ; j < 60;++j)
            {
                dp[i][j] = 0;
            }
        }
        for(int i = 1 ; i <= min(N,M);++i)
        {
            dp[1][i] = 1;
        }
        long long int ans = findAns();
        cout << ans <<endl;
    }
    return 0;
}
