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
string name[30][30];
int nameMark[30][30];
int num[30];
int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;++t)
    {
        G.clearG(1000);
        int N;
        int counts = 1;
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> num[i];
            for(int j = 0 ; j < num[i];++j)
            {
                cin >> name[i][j];
                nameMark[i][j] = counts++;
                for(int k = 0 ; k < name[i][j].length();++k)
                {
                    if(k == 0)
                    {
                        if(name[i][j][k] >= 'a' && name[i][j][k] <= 'z')
                        {
                            name[i][j][k] = name[i][j][k]-'a' + 'A';
                        }
                    }
                    else
                    {
                        if(name[i][j][k] >= 'A' && name[i][j][k] <= 'Z')
                        {
                            name[i][j][k] = name[i][j][k]-'A' + 'a';
                        }
                    }
                }
            }
        }
        for(int i = 1 ; i <=26;++i)
        {
            G.AddEdge(0,i,1);
        }
        for(int i = 0 ; i < N;++i)
        {
            G.AddEdge(i+26+1,N+26+1,1);
        }
        for(int i = 0 ; i < 26;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                for(int k = 0 ; k < num[j];++k)
                {
                    if( 'A'+i == name[j][k][0])
                    {
                        G.AddEdge(i+1,26+j+1,1);
                    }
                }
            }
        }
        G.Maxflow(0,N+26+1);
        printf("Case #%d:\n",t);
        for(int i = 1 ;i <= N;++i)
        {
            int status = 0;
            for(int j = 0 ; j < G.G[i].size() && !status;++j)
            {
                if(G.edges[ G.G[i][j]].flow == 1 )
                {
                    for(int k = 0 ; k < num[G.edges[ G.G[i][j]].to-27];++k)
                    {
                        if(name[G.edges[ G.G[i][j]].to-27][k][0] == 'A'+i-1)
                        {
                            cout << name[G.edges[ G.G[i][j]].to-27][k] <<endl;
                            status = 1;
                            break;
                        }
                    }
                }
            }
        }

    }
    return 0;
}
