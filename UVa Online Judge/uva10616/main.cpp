#include <iostream>
#include <cstring>
using namespace std;
int dp[205][15][23];
int num[205];
int N,Q,M,D;
int mod(int a,int n)
{
    int r = a % n;
    if(r < 0) r = r+n;
    return r;
}
int findAns(int depth,int choose,int curNum)
{
    if(depth >= N && choose < M)
    {
        return 0;
    }
    else if(choose == M)
    {
        return dp[depth][choose][curNum] = (curNum == 0);
    }
    else if(dp[depth][choose][curNum]  != -1)
    {
        return dp[depth][choose][curNum] ;
    }
    else
    {
        int a = findAns(depth+1,choose,mod(curNum ,D) );
        int b = findAns(depth+1,choose+1,mod(mod( curNum,D) + mod(num[depth],D),D) );
        //cout << depth+1 << "  " << curNum << "  "<<num[depth] << "   " << mod(mod( curNum,D) + mod(num[depth],D),D)  << "   " << choose<<endl;
        //cout << a << "   " << b <<endl;
        return dp[depth][choose][curNum]  = a + b;
    }

}
int main()
{
    int t = 1;
    while(cin >> N && cin >> Q)
    {
        if(!N && !Q) break;
        for(int i = 0 ; i < N;++i)
        {
            cin >> num[i];
        }
        cout << "SET " << t++ << ":\n";
        for(int i = 0 ; i < Q;++i)
        {
            cin >> D >> M;
            cout << "QUERY " << i+1 << ": ";
            memset(dp,-1,sizeof(dp));
            cout << findAns(0,0,0) <<endl;;
        }
    }
    return 0;
}
