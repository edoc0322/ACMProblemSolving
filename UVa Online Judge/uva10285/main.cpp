#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int m[101][101];
int dp[101][101];
int R,C;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int dfs(int i,int j)
{
    if(dp[i][j])
    {
        //cout << i << " " << j <<endl;
        return dp[i][j];
    }
    int ok = 0;
    for(int k = 0; k <4;++k)
    {
        int nx = j + dx[k];
        int ny = i + dy[k];
        //cout << nx << " nx and ny " << ny <<endl;
        //cout << R << " R and  C" << C <<endl;

        if(nx >= 0 && nx < C && ny >= 0 && ny < R && m[ny][nx] < m[i][j])
        {
            //cout << "??\n";
            ok = 1;
            dp[i][j] = max(dp[i][j],dfs(ny,nx) + 1);
        }
    }
    if(ok == 0)
    {
        //cout << i << " " << j <<endl;
        dp[i][j] = 1;
        return dp[i][j];
    }
    else
    {
        return dp[i][j];
    }
}
int main()
{

    int N;
    cin >> N;
    string name;

    while(N>0)
    {
        cin >> name;
        R,C;
        cin >> R;
        cin >> C;
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                cin >> m[i][j];
                dp[i][j] = 0;
            }
        }
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if(dp[i][j]==0)
                {
                    dfs(i,j);
                }
            }
        }
        int maxI = -1;
        int ini,inj;
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if(dp[i][j]> maxI)
                {
                    ini = i;
                    inj = j;
                    maxI = dp[i][j];
                }
            }
        }
        cout << name<<": "<<maxI<<endl;


        N--;
    }


    return 0;
}
