#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int d[505];
int maps[505][505];
int n,m;
bool visit[505];

struct node
{
    int p;
    double d;

};
struct edge
{
    int s,t;
} edges[250005];
bool operator< (const node& n1, const node& n2)
{
    return n1.d > n2.d;
}
int main()
{
    int test = 1;
    while(cin >> n >> m)
    {
        if(!n && !m) break;
        for(int i = 1 ; i <= n;++i)
        {
            for(int j = 1 ; j <= n;++j)
            {
                maps[i][j] =1e9;
            }
            d[i] = 1e9;
        }
        for(int i = 0 ; i < m;++i)
        {
            int s,t;
            double w;
            cin >> s >> t >> w;
            edges[i].s = s;
            edges[i].t = t;
            maps[s][t] = w;
            maps[t][s] = w;

        }
        memset(visit,false,sizeof(visit));
        priority_queue<node> pq;
        d[1] = 0;
        pq.push((node) {1,d[1]});
        for(int i = 1 ; i <= n;++i)
        {
            int a= -1;
            while(!pq.empty() && visit[a = pq.top().p])
            {
                pq.pop();
            }
            if( a== -1)
            {
                break;
            }
            visit[a] = true;
            for(int j = 1;j <= n;++j)
            {
                if(!visit[j] && d[a]+maps[a][j] < d[j])
                {
                    d[j] = d[a] + maps[a][j];
                    pq.push((node){j,d[j]});
                }
            }
        }
        //cout << d[1] << " " << d[2] << " " << d[3] <<endl;
        double maxD1=-1;
        int maxIndex1 = -1;
        for(int i= 1 ; i <= n;++i)
        {
            if(d[i] != 1e9 && d[i] > maxD1)
            {
                maxD1 = d[i];
                maxIndex1 = i;
            }

        }
        double maxD2 = -1;
        int maxIndex2[2] = {-1,-1};
        for(int i = 0 ; i < m;++i)
        {
            if(d[edges[i].s] != 1e9 && d[edges[i].t] != 1e9)
            {
                if(d[edges[i].s] > d[edges[i].t])
                {
                    if(d[edges[i].s] + (double)(maps[edges[i].s][edges[i].t] - (d[edges[i].s] -d[edges[i].t] ))/2 > maxD2)
                    {

                        maxIndex2[0] = edges[i].s;
                        maxIndex2[1] = edges[i].t;
                        maxD2 = d[edges[i].s] + (double)(maps[edges[i].s][edges[i].t] - (d[edges[i].s] -d[edges[i].t] ))/2;
                    }
                }
                else
                {
                    if(d[edges[i].t] + (double)(maps[edges[i].t][edges[i].s]  - (d[edges[i].t] -d[edges[i].s] ))/2 > maxD2)
                    {
                        //cout << "WTF?" <<endl;
                        maxIndex2[0] = edges[i].s;
                        maxIndex2[1] = edges[i].t;
                        maxD2 = d[edges[i].t] + (double)(maps[edges[i].t][edges[i].s]  - (d[edges[i].t] -d[edges[i].s] ))/2;
                    }
                }
            }
        }
        cout << "System #" << test++ <<endl;
        if(maxD1 + 1e-8 > maxD2)
        {
            cout << "The last domino falls after " << fixed << setprecision(1) << maxD1 << " seconds, at key domino " << maxIndex1 << "." <<endl;
        }
        else
        {
            int L,R;
            L = maxIndex2[0] < maxIndex2[1] ? maxIndex2[0] : maxIndex2[1];
            R = maxIndex2[0] > maxIndex2[1] ? maxIndex2[0] : maxIndex2[1];
            cout << "The last domino falls after " << fixed << setprecision(1) << maxD2
            << " seconds, between key dominoes " << L << " and " << R << "." <<endl;
        }
        cout <<endl;



    }
    return 0;
}
