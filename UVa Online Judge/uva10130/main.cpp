#include <iostream>
#include <algorithm>
using namespace std;

int w[1001];
int v[1001];
int bag[101];
int item_pick[1001];
int N;
int P;
int dp[1001][1001];
int prev[1001][1001];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int test;
    cin >> test;

    while(test > 0)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> v[i];
            cin >> w[i];
        }
        cin >> P;
        for(int i = 0 ; i < P;++i)
        {
            cin >> bag[i];
        }
        sort(bag,bag+P,cmp);
        for(int j = 0 ; j <= N;++j)
        {
            item_pick[j] = 0;
        }
        int sum = 0;
        for(int i = 0 ; i < P ;++i)
        {
            for(int j = 0 ; j <= N;++j)
            {
                for(int k = 0 ; k <= 30;++k)
                {
                    dp[j][k] = 0;
                    prev[j][k] = 0;
                }
            }
            int t;
            for(int j = 0 ; j < N;++j)
            {
                for(int k = 0 ; k <= bag[i];++k)
                {
                    if(k >= w[j] )
                    {
                        dp[j+1][k] = max(dp[j][k],dp[j][k-w[j]]+v[j]);
                        /*
                        if(dp[j][k-w[j]]+v[j] > dp[j][k])
                        {
                            dp[j+1][k] = dp[j+1][k-w[j+1]]+v[j+1];
                            //prev[j][k] = 1;
                        }
                        else
                        {
                            dp[j+1][k] = dp[j][k];
                        }
                        */

                    }

                    else
                    {
                        dp[j+1][k] = dp[j][k];
                    }

                }
            }
            //cout << dp[N][bag[i]]<<endl;
            sum+= dp[N][bag[i]];
            /*
            for(int j = bag[i],k = N-1;k>=0;--k)
            {
                if(prev[k][j])
                {
                    cout << bag[i] << "  " << k<< endl;
                    sum+= v[k];
                    item_pick[k] = 1;
                    j -= w[k];
                }
            }
            */




        }
        cout << sum <<endl;


        test--;
    }
    return 0;
}
