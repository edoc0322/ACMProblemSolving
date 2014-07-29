#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int dp[21][4001];
int w[21];
int main()
{
    int test;
    char s[100];
    char *temp;
    cin >> test;
    getchar();
    while(test > 0)
    {
        int N = 0;
        cin.getline(s,100);
        temp = strtok(s," ");
        int sumW = 0;
        while(temp!= NULL)
        {
            w[N++] = atoi(temp);
            sumW += w[N-1];
            temp = strtok(NULL," ");
        }
        if(sumW %2)
        {
            cout <<"NO\n";
            test--;
            continue;
        }
        for(int i = 0 ; i <= N;++i)
        {
            for(int j = 0 ; j <= sumW/2;++j)
            {
                dp[i][j] = 0;
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j <= sumW/2;++j)
            {
                if(j >= w[i])
                {
                    dp[i+1][j] = max(dp[i][j] , dp[i][j-w[i]] + w[i]);
                }
                else
                {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        if(dp[N][sumW/2] == sumW/2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        test--;
    }

    return 0;
}
