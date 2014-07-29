#include <iostream>
#include <vector>


using namespace std;

int dp[21][100000];
int prev[21][100000];
int maxW;
int n;
int w[21];
vector<int> cds;

int main()
{
    while(cin >> maxW)
    {
        cds.clear();
        cin >> n;
        for(int i = 0 ; i < n;++i)
        {
            cin >> w[i];
        }
        for(int i = 0 ; i<= n;++i)
        {
            for(int j = 0 ; j <= maxW;++j)
            {
                dp[i][j] = 0;
                prev[i][j] = 0;
            }
        }
        for(int i = 0 ; i < n;++i)
        {
            for(int j = 0 ; j <= maxW;++j)
            {
                if(j < w[i])
                {
                    dp[i+1][j] = dp[i][j];
                }
                else
                {
                    if(dp[i][j-w[i]]+w[i] > dp[i][j])
                    {
                        dp[i+1][j] = dp[i][j-w[i]]+w[i];
                        prev[i][j] = 1;
                    }
                    else
                    {
                        dp[i+1][j] = dp[i][j];
                    }
                }
            }
        }
        for(int i = n-1,j = maxW ;i>=0;i--)
        {
            if(prev[i][j])
            {
                cds.push_back(w[i]);
                j-= w[i];
            }
        }
        for(int i = cds.size()-1 ; i >=0;--i)
        {
            cout << cds[i]<<" ";
        }
        cout << "sum:" << dp[n][maxW]<<endl;


    }

    return 0;
}
