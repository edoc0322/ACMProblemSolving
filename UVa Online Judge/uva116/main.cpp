#include <iostream>
#include <algorithm>

using namespace std;
int maps[150][150];
int dp[150][150];
int prev[150][150];
int R,C;
int main()
{
    while(cin >> R &&cin >>C)
    {
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                cin >> maps[i][j];

            }
        }
        for(int i = 0 ; i < R;++i)
        {
            dp[i][C-1] = maps[i][C-1];
        }
        for(int i = C-2;i>=0;--i)
        {
            for(int j = 0 ; j < R;++j)
            {
                int curMin = 99999999;
                for(int k = -1;k<=1 ; ++k)
                {
                    int newY = (k+j+R) % R;
                    if(curMin > dp[newY][i+1] || (curMin == dp[newY][i+1] && newY < prev[j][i]))
                    {
                        curMin = dp[newY][i+1];
                        prev[j][i] = newY;
                    }
                }
                dp[j][i] = maps[j][i] + curMin;
                //cout << "i  j " <<i << " " << j <<endl;
                //cout << upSum << " " << midSum << " " << downSum <<endl;
            }
        }
        int minY = 9999999;
        int index = 0;
        for(int i = 0 ; i < R;++i)
        {
            //cout << dp[i][0] <<endl;
            if(dp[i][0] < minY)
            {
                minY = dp[i][0];
                index = i;
            }
        }
        for(int i = 0 ,j = index; i < C;++i)
        {
            if(i == 0) cout << j+1;
            else
            {

                cout << " " << j+1;
            }
            j = prev[j][i];

        }
        cout <<endl;
        cout << dp[index][0] <<endl;
    }
    return 0;
}
