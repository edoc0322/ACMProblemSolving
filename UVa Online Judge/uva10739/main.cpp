#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];

int findAns(string s,int i,int j)
{
    if(i >= j)
    {
        return 0;
    }
    if(dp[i][j] != 0)
    {
        return dp[i][j];
    }
    if(s[i] == s[j])
    {
        dp[i][j] = findAns(s,i+1,j-1);
    }
    else
    {
        dp[i][j] = min(findAns(s,i+1,j), min(findAns(s,i,j-1),findAns(s,i+1,j-1))) + 1;
    }
    return dp[i][j];
}


int main()
{
    int t;
    cin >> t;
    int counts = 1;
    while(t--)
    {
        string s;
        cin >> s;
        for(int i = 0 ; i < s.length();++i)
        {
            for(int j = 0 ; j < s.length();++j)
            {
                dp[i][j] = 0;
            }
        }
        findAns(s,0,s.length()-1);
        cout << "Case " << counts++ << ": ";
        cout << dp[0][s.length()-1] <<endl;
    }
    return 0;
}
