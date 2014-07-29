#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#define INF 99999999

using namespace std;

struct Edge
{
    int from,to,cap,flow;
};
struct Dinic
{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[1000];
    bool vis[1000];
    int d[1000];
    int cur[1000];
    void clearD()
    {
        for(int i = 0 ; i <= n;++i)
        {
            G[i].clear();
        }
        edges.clear();
        memset(d,0,sizeof(d));
    }

    void AddEdge(int from,int to,int cap)
    {
        edges.push_back((Edge) {from,to,cap,0});
        edges.push_back((Edge) {to,from,0,0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while(!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for(int i = 0 ; i < G[x].size();++i)
            {
                Edge& e = edges[G[x][i]];
                if(!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a)
    {
        if(x == t || a== 0) return a;
        int flow = 0,f;
        for(int& i = cur[x]; i < G[x].size();++i)
        {
            Edge& e = edges[G[x][i]];
            if(d[x] + 1 == d[e.to] && (f = DFS(e.to , min(a,e.cap - e.flow))) > 0 )
            {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if( a == 0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s,int t)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow += DFS(s,INF);
        }
        return flow;
    }
};

int main()
{
    Dinic G;
    map<string,int> maps;
    maps["XXL"] = 100;
    maps["XL"] = 101;
    maps["L"] = 102;
    maps["M"] = 103;
    maps["S"] = 104;
    maps["XS"] = 105;

    int test;
    cin >> test;
    while(test--)
    {
        G.n = 500;
        G.clearD();
        int N,M;
        cin >> N >> M;
        int s = 0,t = 300;
        G.AddEdge(s,maps["XXL"],N/6);
        G.AddEdge(s,maps["XL"],N/6);
        G.AddEdge(s,maps["L"],N/6);
        G.AddEdge(s,maps["M"],N/6);
        G.AddEdge(s,maps["S"],N/6);
        G.AddEdge(s,maps["XS"],N/6);
        string a,b;
        for(int i = 1 ; i <= M;++i)
        {
            cin >> a >> b;
            G.AddEdge(maps[a],i,1);
            G.AddEdge(maps[b],i,1);
            G.AddEdge(i,t,1);
        }
        int ans = G.Maxflow(s,t);
        //cout << ans << endl;
        if(ans == M)
        {
            cout << "YES" <<endl;
        }
        else
        {
            cout << "NO" <<endl;
        }

    }
    return 0;
}
