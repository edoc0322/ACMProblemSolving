#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>
#define maxI 99999999
#define min(a,b)  ((a) < (b) ? (a) : (b))
using namespace std;
int dp[305];
int weight[101];
int value[101];
int M;
int main()
{
    double temp;
    int cases = 1;
    while(cin >> temp)
    {
        weight[0] = 1;
        value[0] = round(temp*100);
        cin >> M;
        int num;
        for(int i = 1 ; i <= M;++i)
        {
            cin >> num >> temp;
            weight[i] = num;
            value[i] = round(temp*100);
        }
        for(int i = 0 ; i < 305;++i)
        {
            dp[i] = maxI;
        }
        dp[0] = 0;
        for(int i = 0 ; i <= M;++i)
        {
            for(int j = 0 ; j < 305;++j)
            {
                if(dp[j] != maxI)
                {
                    if(j+weight[i] < 305)
                    {
                        dp[j+weight[i]] = min(dp[j+weight[i]] ,dp[j]+value[i]);
                    }

                }
            }
        }
        getchar();
        string s;
        getline(cin,s);
        stringstream ss;
        ss << s;
        int target;
        cout << "Case " << cases++ << ":\n";
        while(ss >> target)
        {
            int minN = maxI;
            for(int i = target;i< 305;++i)
            {
                minN = min(minN,dp[i]);
            }
            printf("Buy %d for $%d.%.2d\n",target,minN/100,minN%100);
        }


    }

    return 0;
}
