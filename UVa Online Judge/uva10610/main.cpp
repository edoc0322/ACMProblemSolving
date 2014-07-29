#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define inf 10000000
using namespace std;
double V,M;
const int maxN = 2001;
int maps[maxN][maxN];
double hx[maxN];
double hy[maxN];
int d[maxN];

int N;


double dist(double x1,double y1, double x2, double y2)
{
    return sqrt( pow(x1-x2,2) + pow(y1-y2,2));
}

void bfs(int s,int e)
{
    queue<int> que;
    que.push(s);
    for(int i = 0 ; i < N;++i)
    {
        d[i] = inf;
    }
    d[s] = 0;
    while(que.size())
    {
        int p = que.front();
        que.pop();
        if(p == e)
        {
            break;
        }
        for(int i = 0 ; i < N;++i)
        {
            if(maps[p][i] && d[i] > d[p] + 1)
            {
                d[i] = d[p] + 1;
                que.push(i);
            }
        }
    }
}


int main()
{
    char temps[1000];
    while((cin >> V) && (cin >> M))
    {
        if(V == 0.0 && M == 0.0) break;
        getchar();
        N = 0;
        for(int i = 0 ; i < maxN;++i)
        {
            for(int j = 0 ; j < maxN;++j)
            {
                maps[i][j] = 0;
            }
        }
        while(gets(temps) && *temps)
        {
            int ind;
            char *temp1,*temp2;
            temp1 = strtok(temps," ");
            temp2 = strtok(NULL," ");
            hx[N] = atof(temp1);
            hy[N] = atof(temp2);
            for(int i = 0 ; i < N;++i)
            {
                if(dist(hx[i],hy[i],hx[N],hy[N])/V <= M*60)
                {
                    maps[i][N] = maps[N][i] = 1;
                }
            }
            N++;
        }
        bfs(0,1);
        if(d[1] == inf)
        {
            cout << "No.\n";
        }
        else
        {
            cout << "Yes, visiting " << d[1]-1 << " other holes.\n";
        }
    }
    return 0;
}
