// UVa11248 Frequency Hoppingㄩ妏蚚Dinic呾楊
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

const int maxn = 100 + 10;
const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow;
};


bool operator < (const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;    // 晚杅腔謗捷
  vector<int> G[maxn];   // 邁諉桶ㄛG[i][j]桶尨賦萸i腔菴j沭晚婓e杅郪笢腔唗瘍
  bool vis[maxn];         // BFS妏蚚
  int d[maxn];           // 植萸善i腔擒燭
  int cur[maxn];        // 絞說硌渀

  void ClearAll(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void ClearFlow() {
    for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!Q.empty()) {
      int x = Q.front(); Q.pop();
      for(int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if(!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int DFS(int x, int a) {
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i]^1].flow -= f;
        flow += f;
        a -= f;
        if(a == 0) break;
      }
    }
    return flow;
  }

  int Maxflow(int s, int t) {
    this->s = s; this->t = t;
    int flow = 0;
    while(BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }

  vector<int> Mincut() { // call this after maxflow
    vector<int> ans;
    for(int i = 0; i < edges.size(); i++) {
      Edge& e = edges[i];
      if(vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
    }
    return ans;
  }

  void Reduce() {
    for(int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
  }
};
Dinic G;
int main()
{
    int N,M;
    while(cin >> N >> M)
    {
        G.ClearAll(60);
        if(!N && !M)
        {
            break;
        }
        int a,b,c;
        for(int i = 0 ; i < M;++i)
        {
            cin >> a >> b >> c;
            G.AddEdge(a,b,c);
            G.AddEdge(b,a,c);
        }

        G.Maxflow(1,2);
        vector<int> ans = G.Mincut();
        for(int i = 0 ; i < ans.size();++i)
        {
            cout << G.edges[ans[i]].from << " " << G.edges[ans[i]].to <<endl;
        }
        cout <<endl;
    }
    return 0;
}
