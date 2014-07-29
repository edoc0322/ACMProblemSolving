#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int n;
bool visit[50005];
vector<int> maps[50005];
int sums[50005];
int cnt = 0;
int dfs(int u)
{
    visit[u] = true;
    int tot = 0;
    for(int i = 0 ; i < maps[u].size();++i)
    {
       //cout << maps[u][i] <<endl;
        if(!visit[maps[u][i]])
        {
            tot += 1 + dfs(maps[u][i]);
        }
    }
    visit[u] = false;
    return sums[u] = tot;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int t = 1 ; t <= test;++t)
    {

        scanf("%d",&n);
        for(int i = 1 ; i <= n;++i)
        {
            maps[i].clear();
            sums[i] = -1;
        }
        int u,v;
        for(int i = 0 ; i < n;++i)
        {
            scanf("%d %d",&u,&v);
            maps[u].push_back(v);
        }
        int maxD = 0,maxI = 1;
        memset(visit,false,sizeof(visit));
        for(int i = 1 ; i <= n;++i)
        {
            if(sums[i] == -1)
            {
                dfs(i);
                //cout << "i cnt = " << i<< " " << cnt <<endl;
            }
            if(sums[i] > maxD)
            {
                maxD = sums[i];
                maxI = i;
            }
        }
        printf("Case %d: %d\n",t,maxI);
       // cout << "Case " << t <<": " << maxI <<endl;

    }

    return 0;
}
