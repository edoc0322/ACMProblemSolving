#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define INF 10000000
using namespace std;

map<string,int> mapnode;
int prev[500];
int maps[301][301];
vector<int> stacks;
int d[301];
int N;
int E;

int bfs(int s,int e)
{
    queue<int> que;
    que.push(s);
    for(int i = 0 ; i < N;++i)
    {
        prev[i] = -1;
        d[i] = INF;
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
            if(maps[p][i]  && d[i] > d[p]+1)
            {
                d[i] = d[p]+1;
                prev[i] = p;
                que.push(i);
            }
        }

    }
    return d[e];
}

int main()
{
    while(cin >> N)
    {
        string s;
        stacks.clear();
        mapnode.clear();
        int n = 0;
        for(int i = 0 ;i < N;++i)
        {

            char temp[1000];
            sprintf(temp,"%d",i+1);

            mapnode[string(temp)] = i;
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = 0;
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> s;
            int dashi = -1;
            string s1,s2;
            int doi = -1;;
            for(int j= 0 ; j < s.length();++j)
            {
                if(s[j] == '-')
                {
                    dashi = doi = j;
                    s1 = s.substr(0,dashi);

                }
                else if(s[j] == ',')
                {
                    s2 = s.substr(doi+1,j-doi-1);
                    maps[mapnode[s1]][mapnode[s2]] = 1;
                    doi = j;
                    //cout << s2 <<endl;
                }
            }
            if(doi < s.length()-1)
            {
                s2 = s.substr(doi+1,s.length()-doi-1);
                if(s2.length()>=1)
                {
                    maps[mapnode[s1]][mapnode[s2]] = 1;
                    //cout << s2 <<endl;
                }
            }
        }
        cin >> E;
        cout << "-----" <<endl;
        for(int i = 0 ; i < E;++i)
        {
            string sp,ep;
            cin >> sp;
            cin >> ep;
            int ans = bfs(mapnode[sp],mapnode[ep]);
            if(ans == INF)
            {
                cout << "connection impossible"<< endl;
            }
            else
            {
                stacks.clear();
                int k = mapnode[ep];
                while(prev[k] != -1)
                {
                    stacks.push_back(k+1);
                    //cout << k+1 <<endl;
                    k = prev[k];
                }
                cout << mapnode[sp]+1;
                for(int i = stacks.size()-1; i >=0 ;--i)
                {
                    cout << " " << stacks[i];
                }
                cout <<endl;
            }
        }
    }
    return 0;
}
