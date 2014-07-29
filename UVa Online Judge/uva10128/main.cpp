#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long dp[14][14][14];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[1][1][1] = 1;
    for(int n = 2 ; n <= 13;++n)
    {
        for(int front = 1 ; front <= n;++front)
        {
            for(int rear = 1 ; rear <= n;++rear)
            {
                dp[n][front][rear] = dp[n-1][front][rear] * (n-2) + dp[n-1][front-1][rear] + dp[n-1][front][rear-1];
            }
        }
    }
    int N,F,R;
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N>>F>>R;
        cout << dp[N][F][R] <<endl;
    }
    return 0;
}
