#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
string maps[102];
int visit[102][102];
int sy,sx;
int R,C;


int tot ;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
void dfs(int y,int x)
{
    tot++;
    visit[y][x] = 1;
    for(int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] == '0')
        {
            dfs(ny,nx);
        }
    }
}
int main()
{
    int test;
    cin >> test;
    for(int t = 0 ; t < test;++t)
    {
        if(t > 0) cout << endl;
        cin >> sy >> sx;
        sy--;
        sx--;
        getchar();
        string s;
        R = 0;
        while(getline(cin,s) && s[0])
        {
            maps[R] = s;
            R++;
        }
        tot = 0;
        C = maps[0].length();
        memset(visit,0,sizeof(visit));
        dfs(sy,sx);
        cout << tot <<endl;
    }
    return 0;
}
