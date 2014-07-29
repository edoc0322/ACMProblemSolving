#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,int> dp;
int recur(string s)
{
    if(dp[s] != NULL)
    {
        return dp[s];
    }
    int minX = 99999;
    int changed = 0;
    for(int i = 0 ; i < s.length();++i)
    {
        if(i+2 < s.length())
        {
            if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0')
            {
                changed = 1;
                string ns = s;
                ns[i] = '0';
                ns[i+1] = '0';
                ns[i+2] = '1';
                int nans = recur(ns);
                if(nans < minX)
                {
                    minX = nans;
                }
            }
        }
    }

    for(int i = s.length()-1 ; i >=0 ;--i)
    {
        if(i-2 >= 0)
        {
            if(s[i] == '1' && s[i-1] == '1' && s[i-2] == '0')
            {
                changed = 1;
                string ns = s;
                ns[i] = '0';
                ns[i-1] = '0';
                ns[i-2] = '1';
                int nans = recur(ns);
                if(nans < minX)
                {
                    minX = nans;
                }
            }
        }
    }

    if(changed == 0)
    {
        int sums = 0;
        for(int i = 0 ; i < s.length();++i)
        {
            if(s[i] == '1')
            {
                sums++;
            }
        }
        dp[s] = sums;
        return dp[s];
    }
    else
    {
        dp[s] = minX;
        return dp[s];
    }
}

int main()
{

    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        string ns;
        ns = s;
        for(int i = 0 ; i < s.length();++i)
        {
            if(s[i] == 'o')
            {
                ns[i] = '1';
            }
            else
            {
                ns[i] = '0';
            }
        }
        int ans = recur(ns);
        cout << ans <<endl;
    }
    return 0;
}
