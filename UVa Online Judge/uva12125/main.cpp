#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#define INF 99999999
using namespace std;

struct point
{
    int x,y;
    int p;
    double d;
};

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

point nodes[105];
int N;
double dis(point p1,point p2)
{
    return sqrt( pow((double)p1.x-(double)p2.x,(double)2) + pow((double)p1.y-(double)p2.y,(double)2));
}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N;
        double D;
        cin >> D;
        int psums = 0;
        for(int i = 1 ; i <= N;++i)
        {
            cin >> nodes[i].x >> nodes[i].y >> nodes[i].p >> nodes[i].d;
            psums+=nodes[i].p;
        }
        int flag = 0;
        for(int k = 1 ; k <= N;++k)
        {
            G.clearG(200);

            for(int i = 1 ; i <= N;++i)
            {
                G.AddEdge(0,i,nodes[i].p);
                G.AddEdge(i,i+N,nodes[i].d);
            }
            for(int i = 1 ; i <= N;++i)
            {
                for(int j = 1 ; j <= N;++j)
                {
                    if(i!=j)
                    {
                        if(dis(nodes[i],nodes[j])<=D)
                        {
                            G.AddEdge(i+N,j,INF);
                            G.AddEdge(j+N,i,INF);
                        }
                    }
                }
            }
            if(psums == G.Maxflow(0,k))
            {
                if(flag == 0)
                {
                    cout << k-1;
                }
                else
                {
                    cout << " " << k-1;
                }
                flag = 1;
            }
        }
        if(flag)
        {
            cout << endl;
        }
        else
        {
            cout << "-1" <<endl;
        }
    }
    return 0;
}
