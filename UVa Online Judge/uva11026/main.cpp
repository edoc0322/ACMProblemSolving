#include <iostream>
#define max(a,b) ((a)> (b) ? (a) : (b))
using namespace std;
long long int dp[1005][1005];
long long int num[1005];
int main()
{
    int N,K;
    while(cin >> N && cin >> K && N && K)
    {
        num[0] = 0;
        for(int i = 1 ; i <= N;++i)
        {
            cin >> num[i];
        }
        for(int i = 0 ; i <= N;++i)
        {
            for(int j = 0 ; j <= N;++j)
            {
                dp[i][j] = 0;
            }
        }
        for(int i = 0 ; i <= N;++i)
        {
            dp[i][0] = 1;
        }
        dp[1][1] = num[1];
        for(int i = 2 ; i <= N;++i)
        {
            for(int j = 1 ; j <= N;++j)
            {

                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*num[i])%K;
                //cout << "i = " << i << " , j = " << j << " " << " dp[i][j]  = " << dp[i][j]  <<endl;
            }
        }
        long long int maxI = 0;
        for(int i =1 ; i <= N;++i)
        {
            maxI = max(maxI,dp[N][i]);
        }
        cout << maxI <<endl;
    }
    return 0;
}
