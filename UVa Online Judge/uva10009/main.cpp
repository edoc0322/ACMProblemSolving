#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define INF 10000000
using namespace std;

map<string,int> nodes;
string names[301];
int maps[301][301];
int prev[301];
int N;
int d[301];
void bfs(int s,int e)
{
    queue<int> que;
    for(int i = 0 ; i <= N;++i)
    {
        prev[i] = -1;
        d[i] = INF;
    }
    d[s] = 0;
    que.push(s);
    int ok=0;
    while(que.size())
    {
        int point = que.front();
        que.pop();
        if(point == e )
        {
            break;
        }
        for(int i = 1 ;i <= N;++i)
        {
            if(maps[point][i] && d[i] > d[point]+1 )
            {
                d[i] =  d[point]+1;
                prev[i] = point;
                que.push(i);

            }

        }
    }
}

int main()
{
    int test;
    cin >> test;
    int m,n;
    int c = 0;
    while(test--)
    {
        N = 0;
        if(c > 0)
        {
            cout <<endl;
        }
        cin >> m ;
        cin >> n;
        nodes.clear();
        string s1,s2;
        for(int i = 0 ; i <= 300;++i)
        {
            for(int j = 0 ; j <= 300;++j)
            {
                maps[i][j] = 0;
            }
        }
        for(int i = 0; i < m;++i)
        {
            cin >> s1;
            if(nodes[s1] == 0)
            {
                nodes[s1] = N+1;
                names[N] = s1;
                N++;
            }
            cin >> s2;
            if(nodes[s2] == 0)
            {
                nodes[s2] = N+1;
                names[N] = s2;
                N++;
            }
            maps[nodes[s1]][nodes[s2]] = maps[nodes[s2]][nodes[s1]] = 1;
        }
        for(int i = 0 ; i < n;++i)
        {
            vector<int> stacks;
            cin >> s1;
            cin >> s2;
            bfs(nodes[s1],nodes[s2]);
            cout << s1[0];
            int k = nodes[s2];
            while(prev[k] != -1)
            {
                stacks.push_back(k-1);
                k = prev[k];
            }
            for(int i = stacks.size()-1;i>=0;--i)
            {
                cout << names[stacks[i]][0];
            }
            cout << endl;
        }


        c++;
    }

    return 0;
}
