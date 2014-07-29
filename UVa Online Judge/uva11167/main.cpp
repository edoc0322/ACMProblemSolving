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

struct monkey
{
    int st,ed;
    int vol;
};

monkey monkeys[105];
int s[50500];
int N,M;

vector<int> Time;
int findIndex(int x)
{
    return lower_bound(Time.begin(),Time.end(),x) - Time.begin();
}
int main()
{
    int test= 1;
    while(cin >> N)
    {
        if(N == 0) break;
        Time.clear();
        G.clearG(50500);
        cin >> M;
        int v,a,b;
        int sums = 0;
        for(int i = 0 ; i < N;++i)
        {
            cin >> v >> a >> b;
            sums += v;
            monkeys[i].vol = v;
            monkeys[i].st = a;
            monkeys[i].ed = b;
            Time.push_back(a);
            Time.push_back(b);
        }
        sort(Time.begin(),Time.end());
        vector<int>::iterator it;
        it = unique(Time.begin(),Time.end());
        Time.erase(it,Time.end());
        for(int i = 0 ; i < N;++i)
        {
            int low = findIndex(monkeys[i].st);
            int high = findIndex(monkeys[i].ed);
            G.AddEdge(0,i+1,monkeys[i].vol);
            for(int j = low;j < high;++j)
            {
                int dif = Time[j+1] - Time[j];
                G.AddEdge(i+1,N+j+1,dif);
            }
        }
        for(int i = 0 ; i+1 < Time.size();++i)
        {
            int dif = Time[i+1] - Time[i];
            G.AddEdge(N+i+1,N+Time.size()+1,dif*M);
        }
        int ans = G.Maxflow(0,N+Time.size()+1);
        if(ans != sums)
        {
            cout << "Case " << test++ << ": No" <<endl;
        }
        else
        {
            cout << "Case " << test++ << ": Yes" <<endl;
            for(int j=0;j<Time.size();++j)
                s[j]=Time[j];
            for(int i=1;i<=N;++i)
            {
                vector<int> ret;
                cout <<endl;
                cout << "In i monkey " << i <<endl;
                for(int j=0;j<G.G[i].size();++j)
                {
                    Edge&e=G.edges[G.G[i][j]];
                    if(e.flow<=0) continue;
                    int x=e.to-N-1;
              //      cout<<x<<endl;
                     cout << "first Put " << s[x] << "  " << min(Time[x+1],s[x]+e.flow) <<endl;
                    ret.push_back(s[x]);
                    ret.push_back(min(Time[x+1],s[x]+e.flow));
                    cout << "x and s[x] = " << x << "  " << s[x] <<endl;

                    // 這動作代表,有可能有其他猴子一起同這x段開始算,而前面已經有其他猴子佔用了
                    //因此要重算!
                    s[x]+=e.flow;
                    cout << "after +flow = " << s[x] <<endl;
                    cout << "Time[x+1] = " << Time[x+1] <<endl;
                    if(s[x]>=Time[x+1])
                    {

                        s[x]=Time[x]+s[x]-Time[x+1];
                        cout << "Time x ans Time x+1 = " << Time[x] << "  " << Time[x+1] <<endl;
                        if(s[x]>Time[x])
                        {
                            cout << "after Put " << Time[x] << "  " << s[x] <<endl;
                            ret.push_back(Time[x]);
                            ret.push_back(s[x]);
                        }
                    }

                }
                sort(ret.begin(),ret.end());
                for(int j=0;j+1<ret.size();)
                {
                    if(ret[j]==ret[j+1])
                    {
                        ret.erase(ret.begin()+j);
                        ret.erase(ret.begin()+j);
                    }
                    else ++j;
                }
                while(ret.size()%2);
                printf("%d",ret.size()/2);
                for(int j=0;j<ret.size();j+=2)
                    printf(" (%d,%d)",ret[j],ret[j+1]);
                printf("\n");
            }
        }
    }
    return 0;
}
