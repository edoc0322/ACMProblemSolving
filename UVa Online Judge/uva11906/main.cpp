#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;
int maps[105][105];

bool visit[105][105];
int R,C,M,N;
int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};

int main()
{
    int test;
    cin >> test;
    for(int t=  1 ;t <= test; ++t)
    {
        cin >> R >> C >> M >> N;
        int op[8][2];
        op[0][0] = M;    op[0][1] = N;
        op[1][0] = M;    op[1][1] = -N;
        op[2][0] = -M;    op[2][1] = N;
        op[3][0] = -M;    op[3][1] = -N;
        op[4][0] = N;    op[4][1] = M;
        op[5][0] = N;    op[5][1] = -M;
        op[6][0] = -N;    op[6][1] = M;
        op[7][0] = -N;    op[7][1] = -M;
        int water;
        cin >> water;
        int wx,wy;
        memset(maps,0,sizeof(maps));
        memset(visit,false,sizeof(visit));
        for(int i = 0 ; i < water;++i)
        {
            cin >> wx >> wy;
            maps[wx][wy] = -1;
        }
        queue<int> que;
        que.push(0);
        que.push(0);
        visit[0][0] = true;
        while(!que.empty())
        {

            int x,y;
            x = que.front();
            que.pop();
            y = que.front();
           // cout << y << " " << x <<endl;

            que.pop();
            map <pair<int,int>,int> MAP;
            MAP.clear();
            int cnt = 0;
            for(int i = 0 ; i < 8 ;++i)
            {
                int nx = op[i][0] + x;
                int ny = op[i][1] + y;
                //cout << "ny nx = " << ny << " " << nx <<endl;
                if(nx >= 0 && nx < R && ny >= 0 && ny < C && maps[nx][ny] != -1)
                {
                    if(MAP.find(make_pair(nx,ny))==MAP.end()){
                        MAP[make_pair(nx,ny)] = 1;
                        cnt++;
                    }
                    if(!visit[nx][ny])
                    {
                        que.push(nx);
                        que.push(ny);
                        visit[nx][ny] = true;
                    }

                }
            }

            maps[x][y] = cnt;
        }


        int odd = 0;
        int even = 0;
        if(maps[0][0] == 0)
        {
            maps[0][0] = 2;
        }
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < C;++j)
            {
                if(maps[i][j] > 0)
                {
                    if(maps[i][j] % 2)
                        odd++;
                    else
                        even++;
                }
            }

            //cout<< "size = " << maps2[i].size() <<endl;

        }
        cout << "Case " << t << ": " << even << " " << odd  << endl;
    }
    return 0;
}
