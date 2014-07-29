#include <iostream>
#include <cstdio>
#include <queue>
#define inf 100000000
using namespace std;


int maps[31][31][31];
int d[31][31][31];
int L,M,N;
int dx[12] = {0,0,0,0,0,0,0,0,1,0,-1,0};
int dy[12] = {0,0,0,0,0,0,0,0,0,1,0,-1};
int dz[12] = {1,1,1,1,-1,-1,-1,-1,0,0,0,0};
struct points{
    int x,y,z;
};

void bfs(int sx,int sy, int sz,int ex,int ey ,int ez)
{
    for(int i = 0 ; i < L;++i)
    {
        for(int j = 0 ; j < M;++j)
        {
            for(int k = 0 ; k < N;++k)
            {
                d[k][j][i] = inf;
            }
        }
    }
    d[sx][sy][sz] = 0;
    points p;
    p.x = sx;
    p.y = sy;
    p.z = sz;
    //cout << "S " << sx  << " " << sy << " " << sz <<endl;
    //cout << "E " << ex << " " << ey << " " << ez <<endl;
    queue<points> que;
    que.push(p);
    while(que.size())
    {
        p = que.front();
        //cout << "P " << p.x << " " << p.y << " " << p.z <<endl;
        que.pop();
        if(p.x == ex && p.y == ey && p.z == ez) break;
        for(int i = 0 ; i < 12;++i)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];
            //cout << "N " << nx << " " << ny << " " << nz <<endl;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < L && maps[nx][ny][nz] == 0 && d[nx][ny][nz] > d[p.x][p.y][p.z] + 1)
            {
                //cout << "ori " << p.x << " " << p.y << " " << p.z <<endl;
                //cout << "N! " << nx << " " << ny << " " << nz <<endl;
                d[nx][ny][nz] = d[p.x][p.y][p.z] + 1;
                points p2;
                p2.x = nx;
                p2.y = ny;
                p2.z = nz;
                que.push(p2);
            }
        }
    }

}

int main()
{
    while((cin >> L) && (cin >> M) && (cin >> N))
    {
        getchar();
        if(!L && !M && !N) break;
        char input[35];
        int sx,sy,sz;
        int ex,ey,ez;
        for(int i = 0 ;i < L;++i)
        {
            for(int j = 0;j < M;++j)
            {
                cin.getline(input,35);
                for(int k = 0 ; k < N;++k)
                {
                    if(input[k] == 'S')
                    {
                        sx = k;
                        sy = j;
                        sz = i;
                        maps[sx][sy][sz] = 0;
                    }
                    else if(input[k] == 'E')
                    {
                        ex = k;
                        ey = j;
                        ez = i;
                        maps[ex][ey][ez] = 0;
                    }
                    else if(input[k] == '#')
                    {
                        maps[k][j][i] = 1;
                    }
                    else
                    {
                        maps[k][j][i] = 0;
                    }
                }
            }
            getchar();
        }
        bfs(sx,sy,sz,ex,ey,ez);
        if(d[ex][ey][ez] == inf)
        {
            cout << "Trapped!\n";
        }
        else
        {
            cout << "Escaped in " << d[ex][ey][ez] << " minute(s).\n";
        }

    }
    return 0;
}
