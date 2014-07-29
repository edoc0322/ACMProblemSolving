#include <iostream>

using namespace std;
int dp[10001][10001];
int v[26];

int L,S;
void findAns(int sum,int dep)
{

    if(dep == 27)
    {
        int sums = 0;
        for(int i = 0 ; i  < 26;++i)
        {
            sums += v[i];
        }
        dp[sums][sum]++;
        return;
    }
    else
    {

        v[dep] = 1;
        findAns(sum + dep + 1, dep + 1);
        v[dep] = 0;
        findAns(sum,dep+1);
        return ;

    }
}
int main()
{
    for(int i = 0 ; i < 26;++i)
    {
        v[i] = 0;
    }
    for(int i = 0 ; i < 10001;++i)
    {
        for(int j = 0 ; j < 10001;++j)
        {
            dp[i][j] = 0;
        }
    }
    findAns(0,0);
    int counts = 1;
    while(cin >> L && cin >> S && L && S )
    {
        cout << "Case " << counts++ << ": " << dp[L][S] <<endl;
    }

    return 0;
}
