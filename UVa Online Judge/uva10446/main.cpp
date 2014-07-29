#include <iostream>
#include <algorithm>
using namespace std;
int count1;
int N,B;
unsigned long long dp[65][65];
int trib(int n, unsigned int back)
{
    int sum=0;
    int i;
    //cout << n << " " << back <<endl;
    count1++;
    if(n<=0) return 0;
    if(n==1) return 1;
    for(i=1;i<=back;i++)
         sum+=trib(n-i,back);
    return sum;
}
int main()
{
    int test = 1;
    for(int i = 0;i<=61;++i)
    {
        dp[1][i] = 1;
        dp[0][i] = 1;
        dp[i][1] = i;
        dp[i][0] = 1;
    }
    for(int i = 2 ; i <= 60;++i)
    {
        for(int j = 0 ; j <= 60;++j)
        {
            unsigned long long sums = 0;
            for(int k = 1 ; k <= j;++k)
            {
                if(i-k <= 0)
                {
                    sums += 1;
                }
                else
                {
                    sums+= dp[i-k][j];
                }
            }
            dp[i][j] = sums+1;
        }
    }
    while((cin >> N) && (cin >>B))
    {
        if(N >60)break;
        count1 = 0;
        if(N < 0)
        {
            N = 0;
        }
        //trib(N,B);
        //cout << "Case " << test++ <<": "<< count1<<endl;;
        cout << "Case " << test++ <<": "<< dp[N][B]<<endl;;
    }
    return 0;
}
