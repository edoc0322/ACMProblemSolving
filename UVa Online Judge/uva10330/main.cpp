#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstdio>
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
    vector<int> G[50501];
    bool vis[50501];
    int d[50501];
    int cur[50501];

    void clearG(int n1)
    {
        for(int i = 0 ; i <= n1;++i)
        {
            G[i].clear();
        }
        edges.clear();
        memset(d,1,sizeof(d));
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

Dinic G;
int baseC[105];
int main()
{
    int N;
    while(cin >> N)
    {
        G.clearG(230);
        for(int i = 0 ;i< N;++i)
        {
            cin >> baseC[i];
            G.AddEdge(i+1,N+i+1,baseC[i]);
        }
        int M;
        cin >> M;
        int a,b,c;
        for(int i = 0 ;i < M;++i)
        {
            cin >> a >> b >> c;
            G.AddEdge(N+a,b,c);
        }
        int B,D;
        cin >> B >> D;
        int num;
        for(int i = 0 ; i < B ;++i)
        {
            cin >> num;
            G.AddEdge(0,num,INF);
        }
        for(int i = 0 ; i < D ;++i)
        {
            cin >> num;
            G.AddEdge(num+N,2*N+1,INF);
        }
        cout << G.Maxflow(0,2*N+1) <<endl;

    }
    return 0;
}
