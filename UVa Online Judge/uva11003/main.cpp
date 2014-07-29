#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[7000];
int weight[1005];
int load[1005];
int N;



int main()
{
    while(cin >> N && N)
    {
        for(int i = 0 ; i < N;++i)
        {
            cin >> weight[i] >> load[i];
        }
        int maxAns = 0;
        for(int j = 0 ; j < 7000;++j)
        {
            dp[j] = 0;
        }
        for(int i = 0 ; i < N;++i)
        {

            for(int j = i + 1 ; j < N;++j)
            {
                for(int k = load[j-1] ; k >= weight[j];--k)
                {
                    dp[k] = max(dp[k],dp[k-weight[j]]+1);
                }
            }
        }
        for(int i = 0 ; i < 7000;++i)
        {
            if(dp[i] > maxAns)
            {
                maxAns = dp[i];
                cout << maxAns <<endl;
            }
        }

    }
    return 0;
}
