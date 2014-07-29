#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<int , int> nodes;
int v[32];
int maps[32][32];
int d[32];
int num;
int E;
int starts;
int ttl;

void bfs()
{
    //cout << starts << " " << ttl <<endl;
    queue<int> no;
    no.push(starts);
    int point;
    v[starts] = 1;
    while(!no.empty())
    {
        point = no.front();
        no.pop();
        for(int i = 1;i < num;++i)
        {
            if(maps[point][i] && !v[i])
            {
                if(d[point] + 1 <= ttl)
                {
                    //cout << "visit " << i << endl;
                    d[i] = d[point] + 1;
                    v[i] = 1;
                    no.push(i);
                }
            }
        }
    }

}


int main()
{
    int c = 1;
    while(cin >> E)
    {
        if(!E) break;
        nodes.clear();
        num = 1;
        int a,b;

        for(int i = 1;i<=31;++i)
        {
            v[i] = 0;
            d[i] = 0;
            for(int j = 1 ; j <= 31;++j)
            {
                maps[i][j] = 0;

            }
        }

        for(int i = 0 ; i < E;++i)
        {
            cin >> a;
            cin >> b;
            if(nodes[a] == 0)
            {
                nodes[a] = num++;
            }
            if(nodes[b] == 0)
            {
                nodes[b] = num++;
            }
            maps[nodes[a]][nodes[b]] = maps[nodes[b]][nodes[a]] = 1;
        }
        int orinum;
        while((cin >> orinum) && (cin >> ttl))
        {
            if(!orinum && !ttl) break;
            for(int i = 1;i<=31;++i)
            {
                v[i] = 0;
                d[i] = 0;
            }
            starts = nodes[orinum];
            bfs();
            int ans = 0;
            for(int i = 1 ;i < num;++i)
            {
                if(!v[i])
                {
                    //cout << i << endl;
                    ans++;
                }

            }
            cout <<"Case "<<c++ <<": "<< ans << " nodes not reachable from node " << orinum <<" with TTL = " << ttl << "."<< endl;
        }


    }
    return 0;
}
