#include <iostream>
#include <string>

using namespace std;

int R,C;
int strN;
string maps[105];

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int main()
{
    while(cin >> R >> C >> strN)
    {
        if(!R && !C && !strN) break;

        for(int i = 0 ; i < R;++i)
        {
            cin >> maps[i];
        }
        int x,y,dir;
        int status = 0;
        for(int i = 0 ; i < R && !status;++i)
        {
            for(int j = 0 ; j < C && !status;++j)
            {
                if(maps[i][j]=='N')
                {
                    x = j;
                    y = i;
                    dir = 0;
                    status = 1;
                }
                else if(maps[i][j]=='S')
                {
                    x = j;
                    y = i;
                    dir = 2;
                    status = 1;
                }
                else if(maps[i][j]=='L')
                {
                    x = j;
                    y = i;
                    dir = 1;
                    status = 1;
                }
                else if(maps[i][j]=='O')
                {
                    x = j;
                    y = i;
                    dir = 3;
                    status = 1;
                }
            }
        }
        string command;
        cin >> command;
        int ans = 0;
        for(int i = 0 ; i < strN;++i)
        {
            if(command[i] == 'D')
            {
                dir = (dir+1)%4;
            }
            else if(command[i] == 'E')
            {
                dir--;
                if(dir<0) dir = 3;
            }
            else
            {
                int ny = dy[dir] + y;
                int nx = dx[dir] + x;
                if(ny < R && ny >= 0 && nx < C && nx >= 0 && maps[ny][nx] != '#')
                {
                    y = ny;
                    x = nx;
                    if(maps[y][x] == '*')
                    {
                        ans++;
                        maps[y][x] = '.';
                    }
                }
            }

        }
        cout << ans <<endl;

    }
    return 0;
}
