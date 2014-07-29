#include <iostream>
#define min(a,b) ((a) < (b) ? (a) :(b))
using namespace std;

int N,K;
int num[505];
int dp[505][505];

int main()
{
    int test;
    cin >> test;
    for(int t= 1 ; t <= test;++t)
    {
        cin >> N >> K;
        for(int i = 1 ; i <= N;++i)
        {
            num[i] = i+K;
        }
        for(int i = 0 ; i < 505;++i)
        {
            for(int j = 0 ; j < 505;++j)
            {
                dp[i][j] = 0;
            }
        }
        for(int dis = 2 ; dis <= N;++dis)
        {
            for(int start = 1 ; start+dis-1 <= N;++start)
            {
                int minX = 99999999;
                for(int mid = start ; mid <= start+dis-1;++mid)
                {
                    minX = min(minX,dp[start][mid-1] + dp[mid+1][start+dis-1] + num[mid]*dis);
                }
                dp[start][start+dis-1] = minX;
            }
        }
        cout << "Case " << t << ": " << dp[1][N] <<endl;
    }
    return 0;
}
