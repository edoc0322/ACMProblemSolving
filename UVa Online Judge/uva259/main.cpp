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
    vector<int> G[1000];
    bool vis[1000];
    int d[1000];
    int cur[1000];

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
    G.clearG(200);
    string s;
    int sums = 0;
    while(true)
    {
        while(getline(cin,s) && s[0] )
        {
            stringstream ss;
            ss << s;
            string s1,s2;
            ss >> s1;
            ss >> s2;
            G.AddEdge(s1[0]-'A'+15,100,s1[1]-'0');
            sums += s1[1]-'0';
            for(int i = 0 ; i < s2.length()-1;++i)
            {
                G.AddEdge(s2[i]-'0'+1 , s1[0]-'A'+15,1);
            }

        }

        for(int i = '0' ; i <= '9';++i)
        {
            G.AddEdge(0,i-'0'+1 ,1);
        }
        int ans = G.Maxflow(0,100);
        if(ans != sums)
        {
            cout << "!\n";
        }
        else
        {
            for(int i = '0' ; i <= '9';++i)
            {
                int has = 0;
                for(int j = 0 ; j < G.G[i-'0'+1].size();++j)
                {
                    if(G.edges[G.G[i-'0'+1][j]].flow == 1)
                    {
                        cout << (char) (G.edges[G.G[i-'0'+1][j]].to-15 +'A');
                        has = 1;
                        break;
                    }
                }
                if(has == 0)
                {
                    cout << "_";
                }
            }
            cout <<endl;
        }
        G.clearG(200);
        sums = 0;
        if(cin.eof()) break;
    }
    return 0;
}
