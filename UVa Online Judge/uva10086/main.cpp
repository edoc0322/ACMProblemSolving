#include <iostream>
#include <algorithm>
using namespace std;

int dp[35][305];
int prev[35][305];
int T1,T2;
int N;
int num[35];
int x[35][25];
int y[35][25];

void backtrack(int rest,int xy)
{
    if(rest == 0)
    {
        return;
    }
    backtrack(rest-1,xy - prev[rest][xy]);
    if(rest == 1) cout << prev[rest][xy];
    else cout << " " << prev[rest][xy];
}
int main()
{
    while(cin >> T1 && cin >> T2)
    {
        if(T1 == 0 && T2 == 0) break;
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> num[i];
            x[i][0] = 0;
            y[i][0] = 0;
            for(int j = 1 ; j <= num[i];++j)
            {
                cin >> x[i][j];
            }
            for(int j = 1 ; j <= num[i];++j)
            {
                cin >> y[i][j];
            }
        }
        for(int i = 0 ; i < 35;++i)
        {
            for(int j = 0 ; j < 305;++j)
            {
                dp[i][j] = 99999999;
                prev[i][j] = 99999999;
            }
        }
        dp[0][0] = 0;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0;j <= num[i];++j)
            {
                for(int k = 0;k <= T1;++k)
                {
                    if(dp[i][k]!= 99999999)
                    {
                        if(j + k > T1)break;
                        if(dp[i][k] + x[i][j]+y[i][num[i]-j]  < dp[i+1][k+j])
                        {
                            dp[i+1][k+j] = dp[i][k] + x[i][j]+y[i][num[i]-j] ;
                            prev[i+1][k+j] = j;
                        }
                    }

                }
            }
        }
        cout << dp[N][T1] <<endl;
        backtrack(N,T1);
        cout <<endl;
        cout <<endl;

    }
    return 0;
}
