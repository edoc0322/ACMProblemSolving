#include<cstdio>
#include<cstring>
#include<queue>
#include <cmath>
#include <iostream>

using namespace std;

#define typec int // type of cost

const int V = 105;
const int E = 105*105;
const typec inf=0x3f3f3f3f; // max of cost
int n, m, pre[V], edge[E][3];
typec dist[V];
int relax (int u, int v, typec c)
{
    if (dist[v] > dist[u] + c)
    {
        dist[v] = dist[u] + c;
        pre[v] = u;
        return 1;
    }
    return 0;
}
int bellman (int src)
{
    int i, j;
    for (i=0; i<n; ++i)
    {
        dist[i] = inf;
        pre[i] = -1;
    }
    dist[src] = 0;
    bool flag;
    for (i=1; i<n; ++i)
    {
        flag = false; // 优化
        for (j=0; j<m; ++j)
        {
            if( 1 == relax(edge[j][0], edge[j][1],
                           edge[j][2]) ) flag = true;
        }
        if( !flag ) break;
    }
    for (j=0; j<m; ++j)
    {
        if (1 == relax(edge[j][0], edge[j][1], edge[j][2]))
            return 0; // 有负圈
    }
    return 1;
}




int main()
{
    int test = 1;
    while(cin >> n && n)
    {
        int s;
        cin >> s;
        s--;
        int u,v;
        m = 0;
        while(cin >> u >> v)
        {
            if(!u && !v) break;
            u--;
            v--;
            edge[m][0] = u;
            edge[m][1] = v;
            edge[m][2] = -1;
            m++;

        }
        bellman(s);
        int maxI = 0,index = -1;
        for(int i= 0 ; i < n; ++i)
        {
            if(dist[i] < maxI)
            {
                maxI = dist[i];
                index = i;
            }
        }
        if(index == -1)
        {
            index = s;
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",test++,s+1,-maxI,index+1);
        //cout << maxI << " " << index <<endl;

    }
    return 0;
}
