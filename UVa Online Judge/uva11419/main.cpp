#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstdio>
#include <cstdlib>
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
    vector<int> G[100005];
    bool vis[100005];
    int d[100005];
    int cur[100005];

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
    vector<int> Mincut()   // call this after maxflow
    {
        vector<int> ans;
        for(int i = 0; i < edges.size(); i++)
        {
            Edge& e = edges[i];
            if(vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
        }
        return ans;
    }
};

Dinic G;
int R,C,N;
int main()
{
    while(cin >> R >> C >> N)
    {
        if(!R && !C && !N) break;
        G.clearG(R+C+10);
        int r,c;
        for(int i = 0 ; i < N;++i)
        {
            cin >> r >> c;
            G.AddEdge(r,R+c,1);
        }
        for(int i = 1 ; i <= R;++i)
        {
            G.AddEdge(0,i,1);
        }
        for(int i = 1 ; i <= C;++i)
        {
            G.AddEdge(i+R,R+C+1,1);
        }
        int ans = G.Maxflow(0,R+C+1);
        vector<int> cutAns = G.Mincut();
        cout << ans ;
        for(int i = 0 ; i < cutAns.size();++i)
        {
            if(G.edges[cutAns[i]].from == 0)
            {
                cout <<" r" << G.edges[cutAns[i]].to;
            }
            else
            {
                cout << " c" <<  G.edges[cutAns[i]].from - R;
            }

        }
        cout <<endl;


        cout <<endl;
    }
    return 0;
}
