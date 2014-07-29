#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int maps[105][105];
int weight[105];
int d[105];
bool visit[105];

int n,m;
int maxAns = 0;
int maxNode = 0;
struct node
{
    int n,d;
}nodes[10500];

bool operator <(const  node& n1, const node& n2)
{
    return n1.d < n2.d;
}

void dfs(int u)
{
    //cout << u << " is u " << endl;
    maxAns += weight[u];
    int status = 0;
    int maxD = 0,maxI = 0;
    for(int i = 0 ; i < n; ++i)
    {
        if(maps[u][i] && weight[i] > maxD)
        {
            maxD = weight[i];
            maxI = i;
            status = 1;
        }
    }
    if(status == 0)
    {
        maxNode = u;
        return;
    }
    else
        dfs(maxI);
}

int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test; ++t)
    {
        maxAns = 0;
        cin >> n >> m;
        for(int i = 0 ; i < n;++i)
        {
            cin >> weight[i];
        }
        int u,v;
        memset(maps,0,sizeof(maps));
        memset(visit,false,sizeof(visit));
        for(int i = 0 ; i < m;++i)
        {
            cin >> u >> v;
            maps[u][v] = 1;
        }
        dfs(0);
        cout << "Case " << t << ": ";

        cout << maxAns << " " << maxNode <<endl;


    }
    return 0;
}
