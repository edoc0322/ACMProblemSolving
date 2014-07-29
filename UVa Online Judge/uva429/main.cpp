#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <cstdio>
#define inf 1000000000

using namespace std;

map<string,int> dicNum;
int maps[300][300];
string dic[300];
int d[300];

int N;
bool checkPath(string a,string b)
{
    if(a.length() != b.length()) return false;
    int ans = 0;
    for(int i = 0 ; i < a.length();++i)
    {
        if(a[i] != b[i] ) ans++;
    }
    if(ans == 1) return true;
    else return false;
}
void bfs(int s,int e)
{
    queue<int> que;
    que.push(s);
    for(int i = 0 ; i < N;++i)
        d[i] = inf;

    d[s] = 0;
    while(que.size())
    {
        int p = que.front();
        que.pop();
        if(p == e) break;
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
    char input[1000];
    int test;
    cin >> test;
    int blank = 0;
    getchar();
    while(test--)
    {
        N = 0;
        dicNum.clear();
        for(int i = 0 ; i < 300;++i)
        {
            for(int j = 0 ; j < 300;++j)
            {
                maps[i][j] = 0;
            }
        }
        while(gets(input) && strcmp(input,"*"))
        {
            dicNum[input] = N;
            dic[N] = input;
            for(int i = 0 ; i < N;++i)
            {
                if(checkPath(dic[i],dic[N]))
                {
                    maps[i][N] = maps[N][i] = 1;
                }
            }
            N++;
        }
        if(blank ) cout << endl;
        blank = 1;
        while(gets(input) && *input)
        {
            char *temp;
            temp = strtok(input," ");
            string s = temp;
            temp = strtok(NULL," ");
            string e = temp;
            int si = dicNum[s];
            int ei = dicNum[e];
            bfs(si,ei);
            cout << s << " " << e << " " << d[ei] <<endl;
        }
    }
    return 0;

}
