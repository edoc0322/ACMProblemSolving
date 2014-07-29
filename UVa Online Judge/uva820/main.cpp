#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
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

    int n;
    int test = 1;
    while(cin >> G.n)
    {
        if(G.n == 0) break;
        G.clearD();
        int s,t;
        cin >> s >> t;
        int m;
        int a,b,cap;
        cin >> m;
        while(m--)
        {
            cin >> a >> b >> cap;
            G.AddEdge(a,b,cap);
            G.AddEdge(b,a,cap);
        }
        cout << "Network " << test++ <<endl;
        cout << "The bandwidth is " << G.Maxflow(s,t) << "." <<endl << endl;
    }
    return 0;
}
