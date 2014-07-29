#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;
int N;
int maps[1020][1020];
int visit[1020][1020];
int tot;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int counts = 0;
void dfs(int y,int x,int mark)
{
    counts++;
    visit[y][x] = 1;
    for(int d = 0 ; d < 4 ;++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny >= 0 && ny < N && nx >= 0 && nx < N && !visit[ny][nx] && maps[ny][nx] == mark)
        {
            dfs(ny,nx,mark);
        }
    }
}
int main()
{
    while(cin >> N && N)
    {
        getchar();
        memset(maps,0,sizeof(maps));
        int y,x;
        for(int i = 1 ; i < N;++i)
        {
            string s;
            getline(cin,s);
            stringstream ss;
            ss << s;
            while(ss >> y  && ss >> x)
            {
                y--;x--;
                maps[y][x] = i;
            }
        }
        memset(visit,0,sizeof(visit));
        tot = 0;
        int good = 1;
        for(int i = 0 ; i < N && good;++i)
        {
            for(int j = 0 ; j < N && good; ++j)
            {
                if(!visit[i][j])
                {
                    counts = 0;
                    tot++;
                    dfs(i,j,maps[i][j]);
                    if(counts != N) good = 0;
                }
            }
        }
        //cout << " tot = " << tot <<endl;
        if(tot != N || !good)
            cout << "wrong" <<endl;
        else
            cout << "good" << endl;
    }
    return 0;
}
