#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string maps[60];
int visit[60][60];
int R,C;
int tot = 0;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,-1,0,1};
void dfs(int y,int x)
{
    visit[y][x] = 1;
    if(maps[y][x] == 'G')
    {
        tot++;
    }
    maps[y][x] = '.';
    for(int i = 0 ; i < 4 ;++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && maps[ny][nx] =='T')
            return;
    }
    for(int i = 0 ; i < 4 ;++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] != '#')
            dfs(ny,nx);
    }

}
int main()
{
    while(cin >> C >> R)
    {
        for(int i = 0 ; i < R;++i)
        {
            cin >> maps[i];
        }
        int sy = -1,sx = -1;
        for(int i = 0 ; i < R && sy == -1;++i)
        {
            for(int j = 0 ; j < C && sy == -1;++j)
            {
                if(maps[i][j] == 'P')
                {
                    sy = i;
                    sx = j;
                }
            }
        }
        tot = 0;
        memset(visit,0,sizeof(visit));
        dfs(sy,sx);
        cout << tot <<endl;
    }
    return 0;
}
