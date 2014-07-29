#include <iostream>

using namespace std;

long long int dp[102][102];
int N,K;
int main()
{
    while(cin >> N && cin >> K)
    {
        if(N == 0 && K == 0) break;
        for(int i = 0 ; i <= K;++i)
        {
            for(int j = 0 ; j <=N ;++j)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 1 ; i <= K;++i)
        {
            for(int j = 0;j <= N;++j)
            {
                long long int sums = 0;
                for(int k = 0; k <= N;++k)
                {
                    if(j-k >= 0) sums += dp[i-1][j-k];
                }
                dp[i][j] = sums % 1000000;
                cout << i << " " << j << " " <<dp[i][j] <<endl;
            }
        }
        cout << dp[K][N] <<endl;
    }


    return 0;
}
