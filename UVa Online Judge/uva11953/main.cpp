#include <iostream>
#include <string>
using namespace std;
int N;
string maps[105];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
void dfs(int y,int x)
{
    maps[y][x] = '.';
    for(int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 0 && ny < N && nx >= 0 && nx < N && maps[ny][nx] != '.')
        {
            dfs(ny,nx);
        }
    }
}
int main()
{
    int T;
    cin >> T;
    for(int t = 1 ; t <= T;++t)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> maps[i];
        }
        int ans = 0;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                if(maps[i][j] == 'x')
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout << "Case " << t << ": " << ans <<endl;

    }
    return 0;
}
