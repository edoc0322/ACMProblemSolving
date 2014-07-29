#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
long long int dp[303][303];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1 ; i <= 300;++i)
    {
        for(int j = 0 ; j <= 300;++j)
        {
            if(j - i >= 0)
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    string s;
    while(getline(cin,s))
    {
        int num[3];
        int counts = 0;
        stringstream ss;
        ss << s;
        int temp;
        while(ss >> temp)
        {
            num[counts] = temp;
            counts++;
        }
        if(counts == 1)
        {
            cout << dp[num[0]][num[0]] <<endl;
        }
        else if(counts == 2)
        {
            if(num[1] > num[0])
            {
                num[1] = num[0];
            }
            cout << dp[num[1]][num[0]] <<endl;
        }
        else
        {
            if(num[2] > num[0])
            {
                num[2] = num[0];
            }

            if(num[1] == 0)
            {
                if(num[2] == num[1])
                {
                    cout << dp[num[2]][num[0]] <<endl;
                }
                else
                    cout << dp[num[2]][num[0]] - dp[0][num[0]]<<endl;
            }
            else
            {
                cout << dp[num[2]][num[0]] - dp[num[1]-1][num[0]]<<endl;
            }

        }

    }
    //cout << dp[0][6]<<" "<<dp[1][6] << " "<< dp[2][6] << " " << dp[3][6] << " " << dp[4][6] << " " << dp[5][6] << " " << dp[6][6]<<endl;
    return 0;
}
