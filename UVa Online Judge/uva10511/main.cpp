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
    vector<int> G[15005];
    bool vis[15005];
    int d[15005];
    int cur[15005];

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
    int test;
    cin >> test;
    getchar();
    getchar();
    int blank = 0;
    while(test--)
    {
        if(blank) cout <<endl;
        G.clearG(15000);
        string s;
        int counts1;
        map<string,int> name;
        map<string,int> party;
        map<string,int> club;
        map<int,string> name2;
        int n = 1;
        while(getline(cin,s) && s[0])
        {
            stringstream ss;
            ss << s;
            string n1;
            ss >> n1;
            if(name[n1] == 0)
            {
                name[n1] = n;
                name2[n] = n1;
                n++;
            }
            string p1;
            ss >> p1;
            if(party[p1] == 0)
            {
                party[p1] = n;
                n++;
            }
            G.AddEdge(name[n1],party[p1],1);
            string c1;
            while(ss >> c1)
            {
                if(club[c1] == 0)
                {
                    club[c1] = n;
                    n++;
                }
                G.AddEdge(club[c1],name[n1],1);
            }
        }
        map<string,int>::iterator it;
        for(it = club.begin();it!=club.end();++it)
        {
            G.AddEdge(0,it->second,1);
        }
        for(it = party.begin();it!=party.end();++it)
        {
            G.AddEdge(it->second,n,(club.size()-1)/2);
        }
        int ans = G.Maxflow(0,n);
        if(ans == club.size())
        {
            for(it = club.begin();it!=club.end();++it)
            {
                for(int i = 0 ; i < G.G[it->second].size();++i)
                {
                    if(G.edges[G.G[it->second][i]].flow == 1)
                    {
                        cout << name2[G.edges[G.G[it->second][i]].to] <<" " << it->first  << endl;
                    }
                }
            }
        }
        else
        {
            cout << "Impossible." <<endl;
        }
        blank = 1;
    }
    return 0;
}
