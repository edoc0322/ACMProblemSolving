#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstdio>
#include <string>
#define INF 99999999
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

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


int X,Y,P;
string maps[35];

int main()
{
    while(cin >> X >> Y >> P)
    {
        int s = 0,t = 2000;
        G.clearG(2000);
        for(int i = 0 ; i < X;++i)
        {
            cin >> maps[i];
        }
        for(int i = 0 ; i < X;++i)
        {
            for(int j = 0 ; j < Y;++j)
            {
                if(maps[i][j] == '*')
                {
                    G.AddEdge(s,i*Y+j+1,1 );
                    G.AddEdge(i*Y+j+1,(i*Y+j+1)+X*Y,1 );
                    for(int d= 0 ; d < 4;++d)
                    {
                        int ny = i+dy[d];
                        int nx = j + dx[d];
                        if(ny>=0 && ny < X && nx >=0 && nx < Y)
                        {
                            if(maps[ny][nx]== '.' || maps[ny][nx]== '@' || maps[ny][nx]== '#')
                            {
                                G.AddEdge((i*Y+j+1)+X*Y,ny*Y+nx+1,INF );
                            }
                        }
                    }
                }
                else if(maps[i][j] == '.')
                {
                    G.AddEdge(i*Y+j+1,(i*Y+j+1)+X*Y,1 );
                    for(int d= 0 ; d < 4;++d)
                    {
                        int ny = i+dy[d];
                        int nx = j + dx[d];
                        if(ny>=0 && ny < X && nx >=0 && nx < Y)
                        {
                            if(maps[ny][nx]== '.' || maps[ny][nx]== '@' || maps[ny][nx]== '#')
                            {
                                G.AddEdge((i*Y+j+1)+X*Y,ny*Y+nx+1,INF );
                            }
                        }
                    }
                }
                else if(maps[i][j] == '@')
                {
                    G.AddEdge(i*Y+j+1,(i*Y+j+1)+X*Y,INF );
                    for(int d= 0 ; d < 4;++d)
                    {
                        int ny = i+dy[d];
                        int nx = j + dx[d];
                        if(ny>=0 && ny < X && nx >=0 && nx < Y)
                        {
                            if(maps[ny][nx]== '.' || maps[ny][nx]== '@' || maps[ny][nx]== '#')
                            {
                                G.AddEdge((i*Y+j+1)+X*Y,ny*Y+nx+1,INF );
                            }
                        }
                    }
                }
                else if(maps[i][j] == '#')
                {
                    G.AddEdge((i*Y+j+1)+X*Y,t,P);
                    G.AddEdge((i*Y+j+1),(i*Y+j+1)+X*Y,INF);
                    for(int d= 0 ; d < 4;++d)
                    {
                        int ny = i+dy[d];
                        int nx = j + dx[d];
                        if(ny>=0 && ny < X && nx >=0 && nx < Y)
                        {
                            if(maps[ny][nx]== '.' || maps[ny][nx]== '@' || maps[ny][nx]== '#')
                            {
                                G.AddEdge((i*Y+j+1)+X*Y,ny*Y+nx+1,INF );
                            }
                        }
                    }
                }
            }
        }
        cout << G.Maxflow(0,t) <<endl;
    }
    return 0;
}
