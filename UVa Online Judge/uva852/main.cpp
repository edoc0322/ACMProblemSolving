#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string maps[12];
int R = 9,C = 9;
int status;
int visit[12][12];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int tot;
void dfs(int y,int x)
{
    visit[y][x] = 1;
    tot++;
    for(int d = 0 ; d < 4;++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C)
        {
            if(maps[ny][nx] == 'O')
            {
                if(status == 0)
                {
                    status = 1;
                }
                else if(status == -1)
                {
                    status = 2;
                }
            }
            else if(maps[ny][nx] == 'X')
            {
                if(status == 0)
                {
                    status = -1;
                }
                else if(status == 1)
                {
                    status = 2;
                }
            }
            else if(maps[ny][nx] == '.' && !visit[ny][nx])
            {
                dfs(ny,nx);
            }
        }
    }
}
void dfsW(int y,int x)
{
    visit[y][x] = 1;
    tot++;
    for(int d = 0 ; d < 4;++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] == 'O')
        {
            dfsW(ny,nx);
        }
    }
}

void dfsB(int y,int x)
{
    visit[y][x] = 1;
    tot++;
    for(int d = 0 ; d < 4;++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] == 'X')
        {
            dfsB(ny,nx);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 0 ; i < R; ++i)
        {
            cin >> maps[i];
        }
        memset(visit,0,sizeof(visit));
        int white = 0,black = 0;
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0; j < C;++j)
            {
                if(maps[i][j] == '.' && !visit[i][j])
                {
                    tot = 0;
                    status = 0;
                    dfs(i,j);
                    if(status == 1)
                    {
                        white += tot;
                    }
                    else if(status == -1)
                    {
                        black += tot;
                    }
                }
                else if(maps[i][j] == 'X' && !visit[i][j])
                {
                    tot = 0;
                    dfsB(i,j);
                    black += tot;
                }
                else if(maps[i][j] == 'O' && !visit[i][j])
                {
                    tot = 0;
                    dfsW(i,j);
                    white += tot;
                }
            }
        }
        cout << "Black " << black << " White " << white << endl;
    }
    return 0;
}
