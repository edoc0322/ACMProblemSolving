#include <iostream>
#include <queue>
#define inf 1000000000

using namespace std;
int M,N;
int maps[1005][1005];
int d[1005][1005];
struct points
{
    int x,y;
};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int sx,int sy, int ex,int ey)
{
    queue<points> que;
    for(int i = 0 ; i < M;++i)
    {
        for(int j = 0 ;j<N;++j)
        {
            d[i][j] = inf;
        }
    }
    d[sx][sy] = 0;
    points p;
    p.x = sx;
    p.y = sy;

    que.push(p);
    while(que.size())
    {
        points p1 = que.front();
        que.pop();
        if(p1.x == ex && p1.y == ey) break;
        for(int i = 0 ; i < 4;++i)
        {
            int nx = p1.x + dx[i];
            int ny = p1.y + dy[i];

            if(nx >= 0 && nx < M && ny >=0 && ny < N &&maps[nx][ny] == 0 && d[nx][ny] > d[p1.x][p1.y] + 1)
            {
                d[nx][ny] = d[p1.x][p1.y] + 1;
                points p2;
                p2.x = nx;
                p2.y = ny;
                que.push(p2);
            }
        }
    }

}
int main()
{
    while((cin >> M) && (cin >> N))
    {
        if(!M && !N) break;
        int rows;
        cin >> rows;
        int r;
        int rs;
        for(int i = 0 ; i < M;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = 0;
            }
        }
        for(int i= 0 ; i < rows;++i)
        {
            cin >> r;
            cin >> rs;
            int k;
            for(int j = 0 ; j < rs;++j)
            {
                cin >> k;
                maps[r][k] = 1;
            }
        }
        int sx,sy,ex,ey;
        cin >> sx ;
        cin >> sy;
        cin >> ex;
        cin >> ey;
        bfs(sx,sy,ex,ey);
        cout << d[ex][ey] <<endl;
    }

    return 0;
}
