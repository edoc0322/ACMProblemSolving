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
#define V 100005
using namespace std;


vector<int> vec[V];
int id[V], pre[V], low[V], s[V], stop, cnt, scnt;
void tarjan(int v, int n) // vertex: 0 ~ n-1
{
    int t, minc = low[v] = pre[v] = cnt++;
    vector<int>::iterator pv;
    s[stop++] = v;
    for (pv = vec[v].begin(); pv != vec[v].end(); ++pv)
    {
        if(-1 == pre[*pv]) tarjan(*pv, n);
        if(low[*pv] < minc) minc=low[*pv];
    }
    if(minc < low[v])
    {
        low[v] = minc;
        return;
    }
    do
    {
        id[t = s[--stop]] = scnt;
        low[t] = n;
    }
    while(t != v);
    ++scnt; // 强连通分量的个数
}

int N,M;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N >> M;
        for(int i = 1 ; i <= N;++i)
        {
            vec[i].clear();
            pre[i] = -1;
        }
        stop = cnt = scnt = 0;
        int a,b;
        for(int i = 0 ; i < M; ++i)
        {
            cin >> a >> b;
            vec[a].push_back(b);
        }
        int ans = 0;
        for(int i = 1 ; i<= N;++i)
        {
            if(pre[i] == -1)
            {
                ans++;
                tarjan(i,N);
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
