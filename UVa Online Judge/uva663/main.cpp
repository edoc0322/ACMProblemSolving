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
    vector<int> G[50501];
    bool vis[50501];
    int d[50501];
    int cur[50501];

    void clearG(int n1)
    {
        for(int i = 0 ; i <= n1; ++i)
        {
            G[i].clear();
        }
        edges.clear();
        memset(d,1,sizeof(d));
    }

    void AddEdge(int from,int to,int cap)
    {
        edges.push_back((Edge)
        {
            from,to,cap,0
        });
        edges.push_back((Edge)
        {
            to,from,0,0
        });
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
            for(int i = 0 ; i < G[x].size(); ++i)
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
        for(int& i = cur[x]; i < G[x].size(); ++i)
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
struct slide
{
    int x1,x2,y1,y2;
} slides[50005];

struct point
{
    char c;
    int n;
};

bool cmp(point p1,point p2)
{
    return p1.c < p2.c;
}
int main()
{
    int N;
    int test = 1;
    while(cin >> N && N)
    {
        G.clearG(2*N+1);
        vector<point> ans;
        for(int i = 0 ; i < N; ++i)
        {
            cin >> slides[i].x1 >> slides[i].x2 >> slides[i].y1 >> slides[i].y2;
            G.AddEdge(i+N+1,2*N+1,1);
        }

        int x,y;
        for(int i = 0 ; i < N; ++i)
        {
            cin >> x >> y;
            G.AddEdge(0,i+1,1);
            for(int j = 0 ; j < N; ++j)
            {
                if(x >= slides[j].x1 && x <= slides[j].x2 && y >= slides[j].y1 && y <= slides[j].y2)
                {
                    G.AddEdge(i+1,N+j+1,1);
                }
            }
        }
        int flows = G.Maxflow(0,2*N+1);
        vector<int> cutAns = G.Mincut();
        for(int i = 0 ; i < cutAns.size();++i)
        {
            cout << G.edges[cutAns[i]].from  << "    " << G.edges[cutAns[i]].to <<endl;
            /*
            if(G.edges[cutAns[i]].from == 0)
            {
                cout <<" r" << G.edges[cutAns[i]].to;
            }
            else
            {
                cout << " c" <<  G.edges[cutAns[i]].from - R;
            }
            */

        }
        cout << "Heap " << test++ <<endl;
        if(flows == N)
        {
            for(int i = 1 ; i <= N; ++i)
            {
                for(int j = 0 ; j < G.G[i].size(); ++j)
                {
                    if(G.edges[ G.G[i][j] ].flow == 1)
                    {
                        ans.push_back( (point)
                        {
                            (char)(G.edges[ G.G[i][j] ].to-1-N+'A'),i
                        });
                        break;
                    }
                }
            }
            sort(ans.begin(),ans.end(),cmp);
            for(int i = 0 ; i < ans.size(); ++i)
            {
                if(i == 0) cout << "(" << ans[i].c << "," << ans[i].n << ")";
                else cout << " (" << ans[i].c << "," << ans[i].n << ")";
            }
            cout <<endl;
        }
        else
        {
            cout << "none" <<endl;
        }

        cout <<endl;

    }
    return 0;
}
