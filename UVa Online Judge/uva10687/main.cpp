#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
int n;
struct node{
    double x,y;
}nodes[1005];
struct node2
{
    node n;
    int id;
    double dis;
};

bool operator<(const node2& n1, const node2& n2)
{
    if(n1.dis != n2.dis)
    {
        return n1.dis > n2.dis;
    }
    else if(fabs(n1.dis - n2.dis) < 1e-9)
    {
        if(n1.n.x != n2.n.x)
        {
            return n1.n.x > n2.n.x;
        }
        else
        {
            return n1.n.y > n2.n.y;
        }
    }
}
int maps[1003][1003];
bool visit[1003];

double eucli(node n1,node n2)
{
    return sqrt( pow(n1.x - n2.x,2.0) + pow(n1.y - n2.y,2.0));
}

void dfs(int u)
{
    visit[u] = true;
    for(int j = 0 ; j < n;++j)
    {
        if(!visit[j] && maps[u][j])
        {
            dfs(j);
        }
    }
}
int main()
{
    while(cin >> n && n)
    {
        memset(maps,0,sizeof(maps));
        memset(visit,0,sizeof(visit));
        for(int i = 0 ; i < n;++i)
        {
            cin >> nodes[i].x >> nodes[i].y;
        }
        for(int i = 0 ; i < n;++i)
        {
            priority_queue<node2> pq;
            node2 tempN;
            for(int j = 0;j < n;++j)
            {
                if(i == j ) continue;
                tempN.id = j;
                tempN.n.x = nodes[j].x;
                tempN.n.y = nodes[j].y;
                tempN.dis = eucli(nodes[i],nodes[j]);
                pq.push(tempN);
                //cout << tempN.id <<endl;
            }
            if(!pq.empty())
            {
                node2 n2 = pq.top();
                //cout << "i and j = " << i << "  " << n2.id <<endl;
                maps[i][n2.id] = maps[n2.id][i] = 1;
            }

        }
        int counts = 0;
        for(int i = 0 ; i < n;++i)
        {
            if(!visit[i])
            {
                dfs(i);
                counts++;
            }
        }
        if(counts == 1)
        {
            cout << "All stations are reachable." <<endl;
        }
        else
        {
            cout << "There are stations that are unreachable." << endl;
        }

    }
    return 0;
}
