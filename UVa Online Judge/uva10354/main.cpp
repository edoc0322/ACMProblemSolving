#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int M;
int maps[105][105];
int med[105][105];
int maps2[105][105];
int visit[105];


int main()
{
    int BH,BO,YH,YM;
    while(cin >> N >> M >> BH >> BO >> YH >> YM)
    {
        for(int i = 1 ; i <= N;++i)
        {
            visit[i] = 0;
            for(int j = 1 ; j <= N;++j)
            {
                if(i == j) maps[i][j] = 0;
                else maps[i][j] = 1e9;
                med[i][j] = -1;
            }
        }
        int u,v,c;
        for(int i = 0 ; i < M;++i)
        {
            cin >> u >> v >> c;
            maps[u][v] = maps[v][u] = c;
        }
        memcpy(maps2,maps,sizeof(maps));
        for(int k = 1 ; k <= N;++k)
            for(int i = 1 ; i <= N ; ++i)
            {
                for(int j = 1 ; j <= N; ++j)
                {
                    if(maps[i][k] + maps[k][j] < maps[i][j])
                    {
                        maps[i][j] = maps[i][k] + maps[k][j];
                    }
                }
            }
        for(int i = 1 ; i <= N ; ++i)
        {
            if(maps[BH][i] + maps[i][BO] == maps[BH][BO])
            {
                visit[i] = 1;
            }
        }
        for(int k = 1 ; k <= N;++k)
            for(int i = 1 ; i <= N ; ++i)
            {
                for(int j = 1 ; j <= N; ++j)
                {
                    if(maps2[i][k] + maps2[k][j] < maps2[i][j] && !visit[k] && !visit[i] && !visit[j])
                    {
                        maps2[i][j] = maps2[i][k] + maps2[k][j];
                    }
                }
            }
        if(maps2[YM][YH] == 1e9 || visit[YM] || visit[YH])
        {
            cout << "MISSION IMPOSSIBLE." <<endl;
        }
        else
        {
            cout << maps2[YM][YH] <<endl;
        }




    }
    return 0;
}
