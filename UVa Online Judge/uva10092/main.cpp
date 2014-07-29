#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <sstream>
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
    vector<int> G[1200];
    bool vis[1200];
    int d[1200];
    int cur[1200];

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

int main()
{
    int N,M;
    while(cin >> N >> M)
    {
        G.clearG(1200);
        if(!N && !M)
        {
            break;
        }
        int sums = 0;
        int n1;
        for(int i = 0 ;i < N;++i)
        {
            cin >> n1;
            sums += n1;
            G.AddEdge(0,i+1,n1);
        }
        int n2;
        for(int i = 0 ; i < M;++i)
        {
            cin >> n1;
            for(int j = 0 ; j < n1;++j)
            {
                cin >> n2;
                G.AddEdge(n2,N+i+1,1);
            }
            G.AddEdge(N+i+1,N+M+1,1);
        }
        int ans = G.Maxflow(0,N+M+1);
        if(ans != sums)
        {
            cout << 0 <<endl;
        }
        else
        {
            cout << 1 <<endl;
            for(int i = 1 ;i <= N;++i)
            {
                int status = 0;
                for(int j = 0 ; j < G.G[i].size();++j)
                {
                    if(G.edges[G.G[i][j]].flow == 1)
                    {
                        if(status == 0)
                        {
                            cout << G.edges[G.G[i][j]].to-N;
                            status = 1;
                        }
                        else
                        {
                            cout << " " << G.edges[G.G[i][j]].to-N;
                        }
                    }
                }
                cout <<endl;
            }
        }

    }
    return 0;
}
