#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>
#define inf 10000000
#define maxN 1002
using namespace std;
int E;
int N;

int prev[maxN+1];
int d[maxN+1];
string names[maxN+1];
map<string,int> node;
int maps[maxN+1][maxN+1];

void bfs(int s,int e)
{
    for(int i = 0 ; i < maxN;++i)
    {
        d[i] = inf;
        prev[i] = -1;
    }
    d[s] = 0;
    queue<int> que;
    que.push(s);
    while(que.size())
    {
        int point = que.front();
        que.pop();
        if(point == e) break;
        for(int i = 1 ;i <= N;++i)
        {
            if(maps[point][i] && d[i] > d[point]+1)
            {
                prev[i] = point;
                d[i] = d[point]+1;
                que.push(i);
            }
        }
    }
}

int main()
{

    int c = 0;
    while(cin >> E)
    {
        if(c > 0) cout << endl;
        N = 0;
        for(int i = 0 ; i < maxN;++i)
        {
            for(int j = 0 ; j < maxN;++j)
            {
                maps[i][j] = 0;
            }
        }
        node.clear();
        for(int i =  0 ; i < E;++i)
        {
            string s1,s2;
            cin >> s1;
            if(node[s1] == 0)
            {
                node[s1] = N+1;
                names[N] = s1;
                N++;
            }
            cin >> s2;
            if(node[s2]==0)
            {
                node[s2] = N+1;
                names[N] = s2;
                N++;
            }
            maps[node[s1]][node[s2]] = maps[node[s2]][node[s1]] = 1;
        }
        string st,et;
        cin >> st;
        cin >> et;
        bfs(node[st],node[et]);
        if(!node[st] || !node[et] ||d[node[et]]== inf )
        {
            cout << "No route\n";
        }
        else
        {
            if(node[st] > 0 && st == et)
            {
                cout << st << " " << st << endl;
            }
            else
            {
                vector<int> stacks;
                int k = node[et];
                while(prev[k] != -1)
                {
                    stacks.push_back(k-1);
                    k = prev[k];
                }
                cout << st << " " << names[stacks[stacks.size()-1]]<<endl;
                for(int i = stacks.size()-2;i >= 0;--i)
                {
                    cout << names[stacks[i+1]] << " " << names[stacks[i]]<<endl;
                }
            }
        }


        c++;
    }
    return 0;
}
