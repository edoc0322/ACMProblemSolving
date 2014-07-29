#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 50000+100+10;
const int inf = 1e8;
struct Edge
{
    int u,v;
    int flow,cap;
    Edge(int u,int v,int cap,int flow)
    :u(u),v(v),cap(cap),flow(flow) {}
};

vector<Edge> edges;
vector<int> G[maxn];

void add(int u,int v,int cap)
{
    edges.push_back(Edge(u,v,cap,0));
    edges.push_back(Edge(v,u,0,0));
    int m=edges.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
}

struct ISAP
{
    int d[maxn],cur[maxn];
    int p[maxn],num[maxn];
    int n,s,t;
    void init(int n)
    {
        this->n=n;
    }
    void bfs()
    {
        queue<int> q;
        for(int i=0;i<n;++i)d[i]=inf;
        d[t]=0;
        q.push(t);
        while(q.size())
        {
            int x=q.front();q.pop();
            for(int i=0;i<G[x].size();++i)
            {
                Edge&e=edges[G[x][i]];
                if(e.cap>0||d[e.v]<=d[x]+1) continue;
                d[e.v]=d[x]+1;
                q.push(e.v);
            }
        }
    }
    int Augment()
    {
        int x=t,a=inf;
        while(x!=s)
        {
            Edge&e=edges[p[x]];
            a=min(a,e.cap-e.flow);
            x=e.u;
        }
        x=t;
        while(x!=s)
        {
            edges[p[x]].flow+=a;
            edges[p[x]^1].flow-=a;
            x=edges[p[x]].u;
        }
        return a;
    }

    int maxflow(int s,int t)
    {
        this->s=s,this->t=t;
        bfs();
        memset(cur,0,sizeof(cur));
        memset(num,0,sizeof(num));
        for(int i=0;i<n;++i)
            if(d[i]!=inf) ++num[d[i]];
        int x=s,flow=0;
        while(d[s]<n)
        {
            if(x==t)
            {
                flow+=Augment();
                x=s;
            }
            int ok=0;
            for(int i=cur[x];i<G[x].size();++i)
            {
                Edge&e=edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.v]+1)
                {
                    cur[x]=i;
                    p[e.v]=G[x][i];
                    ok=1;
                    x=e.v;
                    break;
                }
            }
            if(!ok)
            {
                int m=n-1;
                for(int i=0;i<G[x].size();++i)
                {
                    Edge&e=edges[G[x][i]];
                    if(e.cap>e.flow) m=min(m,d[e.v]);
                }
                if(--num[d[x]]==0) break;
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s) x=edges[p[x]].u;
            }
        }
        return flow;
    }
}solver;

int n,m,sum;
vector<int> T;
struct Monkey
{
    int v;
    int a,b;
}mk[110];

typedef vector<int>::iterator Iter;
void input()
{
    sum=0;
    T.clear();
    for(int i=0;i<n;++i)
    {
        scanf("%d%d%d",&mk[i].v,&mk[i].a,&mk[i].b);
        sum+=mk[i].v;
        T.push_back(mk[i].a);
        T.push_back(mk[i].b);
    }
    sort(T.begin(),T.end());
    Iter it=unique(T.begin(),T.end());
    T.erase(it,T.end());
}

int ID(int x)
{
    return lower_bound(T.begin(),T.end(),x)-T.begin();
}

void buildgraph()
{
    edges.clear();
    for(int i=0;i<maxn;++i) G[i].clear();
    for(int i=0;i<n;++i)
    {
        add(0,i+1,mk[i].v);
        int a=ID(mk[i].a),b=ID(mk[i].b);
        for(int j=a;j<b;++j)
        {
            int diff=T[j+1]-T[j];
            add(i+1,n+1+j,diff);
        }
    }
    for(int j=0;j+1<T.size();++j)
    {
        int diff=T[j+1]-T[j];
        add(n+1+j,n+T.size()+1,m*diff);
    }
}

int s[maxn];

void solve()
{
    solver.init(1+n+T.size()+1);
    int ans=solver.maxflow(0,n+T.size()+1);
    if(ans!=sum)
    {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    for(int j=0;j<T.size();++j)
        s[j]=T[j];
    for(int i=1;i<=n;++i)
    {
        vector<int> ret;
        for(int j=0;j<G[i].size();++j)
        {
            Edge&e=edges[G[i][j]];
            if(e.flow<=0) continue;
            int x=e.v-n-1;
      //      cout<<x<<endl;
            ret.push_back(s[x]);
            ret.push_back(min(T[x+1],s[x]+e.flow));
            s[x]+=e.flow;
            if(s[x]>=T[x+1])
            {
                s[x]=T[x]+s[x]-T[x+1];
                if(s[x]>T[x])
                {
                    ret.push_back(T[x]);
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

int main()
{
   // freopen("in.txt","r",stdin);
    int Cas=0;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        input();
        buildgraph();
        ++Cas;
        printf("Case %d: ",Cas);
        solve();
    }
}
