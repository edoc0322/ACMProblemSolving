#include <iostream>
#include <string>
#include <queue>
using namespace std;
int M;
string maps[1000];
int dp[1000][1000];
int v[1000][1000];
int counts;
int countX[10000];
int countY[10000];
int dx[4] = {1 ,0,-1,0};
int dy[4] = {0,-1,0,1};
struct point
{
    int x,y;
};

int bfs(int x,int y)
{
    point p;
    v[y][x] = 1;
    dp[y][x] = 0;
    p.x = x;
    p.y = y;
    queue<point> que;
    que.push(p);
    while(!que.empty())
    {
        point p1 = que.front();
        que.pop();
        for(int i = 0 ; i < 4;++i)
        {

            int nx = p1.x + dx[i];
            int ny = p1.y + dy[i];
            //cout <<nx << "  " << ny <<endl;
            if(nx >= 0 && nx < M && ny >= 0 && ny < M && v[ny][nx] == 0)
            {
                if(dp[ny][nx] > dp[p1.y][p1.x] + 1)
                {
                    dp[ny][nx] = dp[p1.y][p1.x] + 1;
                }
                v[ny][nx] = 1;
                point np;
                np.x = nx;
                np.y = ny;
                que.push(np);
            }
        }
    }
    int maxD2 = 9999999;
    for(int i = 0 ; i < M;++i)
    {
        for(int j = 0 ; j < M;++j)
        {
            if(maps[i][j] == '3')
            {
                if(dp[i][j] < maxD2)
                {
                    maxD2 = dp[i][j];
                }
            }
        }
    }
    return maxD2;
}

int main()
{
    while(cin >> M)
    {
        counts = 0;

        for(int i = 0 ; i < M;++i)
        {
            cin >> maps[i];
            for(int j = 0 ; j < M;++j)
            {
                if(maps[i][j] == '1')
                {
                    countX[counts] = j;
                    countY[counts] = i;
                    counts++;
                }
            }
        }
        int maxD = -1;
        for(int i = 0;i < counts;++i)
        {
            for(int j = 0 ; j < M;++j)
            {
                for(int k = 0 ; k < M;++k)
                {
                    dp[j][k] = 99999999;
                    v[j][k] = 0;
                }
            }
            int ans = bfs(countX[i],countY[i]);
            if(ans > maxD)
            {
                maxD = ans;
            }
        }
        cout << maxD <<endl;
    }


    return 0;
}
