#include <iostream>

using namespace std;

int N,T,P;

int dp[71][71];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> T >> P;
        for(int i = 0 ; i < 71;++i)
        {
            for(int j = 0 ; j < 71;++j)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        int M = T-(P*N);
        for(int i = 1 ; i <= N;++i)
        {
            for(int j = 0; j <= M;++j)
            {
                for(int k = 0 ; k <= M;++k)
                {
                    if(j-k >= 0)
                    {
                        dp[i][j] += dp[i-1][j-k];
                    }
                }
            }
        }
        cout << dp[N][M] <<endl;

    }

    return 0;
}
