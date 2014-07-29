#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


string maps[12];
int visit[15][20];
int R = 10,C = 15;
int tot = 0;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
void dfs(int y,int x,char m)
{
    tot++;
    visit[y][x] = 1;
    for(int d = 0 ; d < 4; ++d)
    {
        int ny= y + dy[d];
        int nx = x + dx[d];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && !visit[ny][nx] && maps[ny][nx] == m)
        {
            dfs(ny,nx,m);
        }
    }
}

void dfs2(int y,int x,char m)
{
    visit[y][x] = 1;
    maps[y][x] = '.';
    for(int d = 0 ; d < 4; ++d)
    {
        int ny= y + dy[d];
        int nx = x + dx[d];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C &&!visit[ny][nx]&& maps[ny][nx] == m)
        {
            dfs2(ny,nx,m);
        }
    }
}

void down()
{
    for(int i = 1 ; i < R;++i)
    {
        for(int j = 0 ; j < C ; ++j)
        {
            if(maps[i][j] != '.')
            {
                int k;
                for(k = 0;k < i ;++k)
                {
                    if(maps[k][j] == '.')
                    {
                        break;
                    }
                }
                if(k != i)
                    swap(maps[i][j],maps[k][j]);
            }
        }
    }
}
void left()
{
    int dis = 0;
    int sc = 0;
    for(int i = 1 ; i < C ;++i)
    {
        for(int j = 0 ; j <= 0 ; ++j)
        {
            if(maps[j][i] != '.')
            {
                dis = 0;
                int k;
                for(k = 0;k < i ;++k)
                {
                    if(maps[j][k] == '.')
                    {
                        break;
                    }
                }
                if(k != i)
                {
                    dis = i - k;
                    sc = i;
                }
            }
            if(dis)
            {
                for(int m = 0 ; m < R ; ++m)
                {
                    swap(maps[m][i],maps[m][i-dis]);
                }
            }
        }
    }


}

int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test ; ++t)
    {
        if(t > 1) cout << endl;
        cout << "Game " << t << ":" <<endl;
        cout << endl;
        for(int i = 9 ; i >= 0 ; --i)
        {
            cin >> maps[i];
        }
        memset(visit,0,sizeof(visit));
        int counts = 150;
        int moves = 1;
        int totalS = 0;
        while(counts > 1)
        {
            int my ,mx ,maxN = -1;
            for(int j = 0 ; j < C; ++j)
            {
                for(int i = 0 ; i < R;++i )
                {
                    tot = 0;
                    if(!visit[i][j] && maps[i][j] != '.')
                    {
                        dfs(i,j,maps[i][j]);
                        if(tot >= 2)
                        {
                            if(tot > maxN)
                            {
                                maxN = tot;
                                my =i;
                                mx = j;
                            }
                            else if(tot == maxN)
                            {
                                if(j < mx)
                                {
                                    my = i;
                                    mx = j;
                                }
                                else if(j == mx)
                                {
                                    if(i < my )
                                    {
                                        my = i;
                                        mx = j;
                                    }
                                }

                            }
                        }
                    }
                }
            }
            if(maxN == -1)
            {
                break;
            }
            else
            {
                cout << "Move " << moves++ << " at (" << my+1 << "," << mx+1 << "): removed " <<
                     maxN << " balls of color " << maps[my][mx] << ", got " << (maxN-2)*(maxN-2) << " points." <<endl;
                totalS += (maxN-2)*(maxN-2);
                memset(visit,0,sizeof(visit));
                dfs2(my,mx,maps[my][mx]);
                memset(visit,0,sizeof(visit));
                down();
                left();
                counts -= maxN;
                /*
                for(int i = R-1 ; i >= 0;--i)
                {
                    cout << maps[i] <<endl;
                }
                */

            }
        }
        if(counts == 0)
        {
            totalS += 1000;
        }
        cout << "Final score: " << totalS << ", with " << counts << " balls remaining." <<endl;





    }
    return 0;
}
