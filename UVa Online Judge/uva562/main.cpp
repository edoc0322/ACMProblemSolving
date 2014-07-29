#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int w[101];
int v[101];
int dp[50001];

int main()
{
    int test;
    cin >> test;
    int N;
    while(test > 0)
    {
        cin >> N;
        int sumW = 0;
        for(int i = 0 ; i < N;++i)
        {
            cin >> w[i];
            sumW+= w[i];
        }

        int hW = sumW/2;

        for(int j = 0; j <= hW;++j)
        {
            dp[j] = 0;

        }

        for(int i = 0 ; i < N;++i)
        {
            for(int j=hW; j>=w[i]; --j)
            {
                dp[j] = max(dp[j] , dp[j-w[i]] + w[i]);
            }
        }
        int t;
        cout << (((t = 2 * dp[hW] - sumW) > 0) ? t : -1*t ) << endl;
        //int sum3 = sumW - dp[N][hW];
        //cout << abs(sum3 - dp[N][hW]) <<endl;



        test--;
    }
    return 0;
}
