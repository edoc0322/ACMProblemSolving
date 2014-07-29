#include <iostream>
#include <string>
using namespace std;

string maps[21];
int R,C;
char land;
int ans = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int visit[21][21];
void dfs(int r,int c)
{
    visit[r][c] = 1;
    ans++;
    for(int i = 0 ; i < 4;++i)
    {
        int ny = r + dy[i];
        int nx = c + dx[i];
        if(nx >= C)
        {
            nx = 0;
        }
        else if(nx < 0)
        {
            nx = C-1;
        }
        if(ny >= 0 && ny < R && nx >=0 && nx < C && maps[ny][nx] == land && visit[ny][nx] == 0)
        {
            dfs(ny,nx);
        }
    }
}

int main()
{
    while(cin >> R && cin >> C)
    {
        for(int i = 0 ; i < R;++i)
        {
            cin >> maps[i];
            for(int j = 0 ; j < C;++j)
            {
                visit[i][j] = 0;
            }
        }

        int y,x;
        cin >> y >> x;
        land = maps[y][x];
        dfs(y,x);
        int maxN = 0;
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if(visit[i][j] == 0 && maps[i][j] == land)
                {
                    ans = 0;
                    dfs(i,j);
                    if(ans > maxN)
                    {
                        maxN = ans;
                    }
                }
            }
        }
        cout << maxN <<endl;

    }
    return 0;
}
