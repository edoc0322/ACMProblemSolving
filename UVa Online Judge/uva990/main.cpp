#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

//int dp[1005];
int dp[32][1005];
int t,w;
int N;
int depth[32],value[32];
int prev[32][1005];
struct node
{
    int index,values;
};
int main()
{
    int counts = 0;
    while(cin >> t && cin >> w)
    {
        if(counts > 0) cout <<endl;
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> depth[i] >> value[i];
        }
        for(int i = 0 ; i <= N;++i)
        {
            for(int j = 0 ; j <= t;++j)
            {
                prev[i][j] = 0;
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i < N;++i)
        {
            int totalTime = 3*depth[i]*w;
            for(int j = t ; j >= 0;--j)
            {
                if(j >= totalTime)
                {
                    if(dp[i][j-totalTime] + value[i]  > dp[i][j])
                    {
                        dp[i+1][j] = dp[i][j-totalTime] + value[i];
                        prev[i][j] = 1;
                    }
                    else
                    {
                        dp[i+1][j] = dp[i][j];
                    }
                }
                else
                {
                    dp[i+1][j] = dp[i][j];
                }

                /*
                if(dp[j-totalTime] + value[i]  > dp[j])
                {
                    dp[j] = dp[j-totalTime] + value[i];
                    prev[i][j] = 1;
                }
                */
            }
        }

        cout << dp[N][t] <<endl;
        vector<int> ans;
        for(int i = N-1 , j = t; i >= 0 ;--i)
        {
            if(prev[i][j])
            {
                ans.push_back(i);
                j-= 3*depth[i]*w;
            }
        }
        cout << ans.size() <<endl;
        for(int i = ans.size()-1;i >= 0;--i)
        {
            cout << depth[ans[i]] << " " << value[ans[i]] <<endl;
        }
        counts++;
    }
    return 0;
}
