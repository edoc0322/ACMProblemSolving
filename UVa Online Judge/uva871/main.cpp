#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int N,M;
string maps[30];
bool visit[30][30];
int blocks;

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
void dfs(int y,int x)
{
    //cout << "y x = " <<y << " " << x <<endl;
    visit[y][x] = 1;
    blocks++;
    for(int d= 0 ; d < 8;++d)
    {
        int ny = dy[d] + y;
        int nx = dx[d] + x;
        if(ny >= 0 && ny < N && nx >= 0 && nx < M && !visit[ny][nx] && maps[ny][nx] == '1')
        {
            dfs(ny,nx);
        }
    }
}
int main()
{
    int test;
    cin >> test;
    getchar();
    getchar();
    int blank = 0;
    string s;
    while(test--)
    {
        if(blank) cout <<endl;
        N = 0;
        M = 0;
        while(getline(cin,s) && s[0])
        {
            maps[N] = s;
            N++;
        }
        M = maps[0].length();
        //cout << N << "   " << M <<endl;
        int ans = 0;
        memset(visit,0,sizeof(visit));
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < M;++j)
            {
                if(!visit[i][j] && maps[i][j] == '1')
                {
                    blocks = 0;
                    dfs(i,j);
                    if(blocks > ans)
                    {
                        ans = blocks;
                    }
                }
            }
        }
        cout << ans <<endl;
        blank = 1;

    }
    return 0;
}
