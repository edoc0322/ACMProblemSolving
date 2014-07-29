#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;


int primeCut[50000];
int prime[500];
int primeN = 0;
int N,K;
int dp[16][190][1150];

int solve(int n,int depth,int choose)
{
    if(n== 0 &&choose == 0)
    {
        //cout << n << "  " << depth << " " << choose <<endl;
        return 1;
    }
    else if(n < 0 || depth >= primeN || choose == 0)
    {
        return 0;
    }
    else if(dp[choose][depth][n] != -1)
    {
        return dp[choose][depth][n];
    }
    else
    {
        return dp[choose][depth][n] = solve(n-prime[depth],depth+1,choose-1) + solve(n,depth+1,choose);
    }

}

int main()
{
    memset(primeCut,1,sizeof(primeCut));
    primeCut[0] = primeCut[1] = 0;
    for(int i = 2 ; i <= 1120;++i)
    {
        if(primeCut[i])
        {
            prime[primeN++] = i;
            for(int k = i+i; k <= 1120;k+=i)
            {
                primeCut[k] = 0;
            }
        }
    }

    //cout << primeN <<endl;




    while(cin >> N && cin >> K)
    {
        if(!N && !K ) break;
        memset(dp,-1,sizeof(dp));
        cout <<  solve(N,0,K) <<endl;

    }

    return 0;
}
