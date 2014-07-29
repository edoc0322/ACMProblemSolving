#include <iostream>

using namespace std;
int h[10000];
int dp[10000];
int main()
{
    int count = 0;
    int testcount = 1;
    while((cin >> h[count]))
    {
        if(h[count]==-1) break;
        count++;
        while((cin >> h[count]))
        {
            if(h[count]==-1) break;
            count++;
        }
        for(int i = 0 ; i < count;++i)
        {
            dp[i] = 1;
        }
        for(int i = count-1 ; i >= 0;--i)
        {
            for(int j = i-1;j>=0;--j)
            {
                if(h[i] < h[j])
                {
                    if(dp[i]+1 > dp[j])
                    {
                        dp[j] = dp[i] + 1;
                    }
                }
            }
        }
        int maxI = 0;
        for(int i = 0 ; i < count;++i)
        {
            if(dp[i] > maxI)
            {
                maxI = dp[i];
            }
        }
        if(testcount > 1)
        {
            cout << endl;
        }
        cout << "Test #"<<testcount <<":"<<endl;
        cout << "  maximum possible interceptions: "<<maxI<<endl;

        testcount++;
        count = 0;
    }
    return 0;
}
