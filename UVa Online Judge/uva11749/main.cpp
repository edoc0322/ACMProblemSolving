#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define minD 1<<31
using namespace std;
int N,M;
int visit[505];
int u;
int v;
int ppa;
int maxPpa;
int maps[505][505];
int dis;


void dfs(int n)
{
    dis++;
    visit[n] = 1;
    for(int i = 1 ; i <= N;++i)
    {
        if(maps[n][i] == maxPpa && !visit[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    while(scanf("%d %d",&N ,&M) == 2)
    {
        if(!N && !M) break;
        maxPpa = minD;
        for(int i = 0 ; i <= N;++i)
        {
            for(int j = 0 ; j <= N ; ++j)
            {
                maps[i][j] = minD;
            }
        }
        for(int i = 0 ; i < M;++i)
        {
            scanf("%d %d %d",&u,&v,&ppa);
            //cin >> u[i] >> v[i] >> ppa[i];
            if(ppa > maps[u][v])
            {
                maps[u][v] = maps[v][u] = ppa;
            }
            maxPpa = max(maxPpa,ppa);
        }
        int ans = -1;
        memset(visit,0,sizeof(visit));
        for(int i = 1 ; i <= N;++i)
        {
            if(!visit[i])
            {
                dis = 0;
                dfs(i);
                if(dis > ans)
                {
                    ans = dis;
                }
            }
        }
        printf("%d\n",ans);
        //cout << ans <<endl;
    }
    return 0;
}
