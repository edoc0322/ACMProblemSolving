#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
string maps[1000];
int visit[1000][1000];
int R = 0;
int C = 0;
int maxCol[1000];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int y,int x,int mark)
{
    visit[y][x] = mark;
    for(int d = 0 ; d < 8; ++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny >= 0 && ny < R && nx >= 0 && nx < C && maps[y][x] == maps[ny][nx] && !visit[ny][nx])
        {
            dfs(ny,nx,mark);
        }
    }
}
int main()
{

    string s;
    while(getline(cin,s) && s[0])
    {
        if(s == "%")
        {
            C = maps[0].length();
            memset(visit,0,sizeof(visit));
            int mark = 1;
            for(int i = 0 ; i < R; ++i)
            {
                for(int j = 0 ; j < C; ++j)
                {
                    if(!visit[i][j])
                    {
                        dfs(i,j,mark);
                        mark++;
                    }
                }
            }
            memset(maxCol,0,sizeof(maxCol));

            for(int j = 0 ; j < C; ++j)
            {
                for(int i = 0 ; i < R; ++i)
                {
                    maxCol[j] = max(maxCol[j],visit[i][j]);
                }
            }
            for(int i = 0 ; i < C; ++i)
            {
                stringstream ss;
                string s2;
                ss << maxCol[i];
                ss >> s2;
                maxCol[i] = s2.length();
            }
            for(int i = 0 ; i < R; ++i)
            {
                for(int j = 0 ; j < C; ++j)
                {
                    if(j == 0)
                    {
                        cout << setw(maxCol[j]) << visit[i][j];
                    }
                    else
                    {
                        cout << setw(maxCol[j]+1) << visit[i][j];
                    }
                }
                cout <<endl;
            }
            cout << "%" <<endl;
            R = 0;

        }
        else
        {
            stringstream ss;
            ss << s;
            string temp;
            maps[R] = "";
            while(ss >> temp)
            {
                maps[R] += temp;
            }
            R++;
        }
    }

    C = maps[0].length();
    memset(visit,0,sizeof(visit));
    int mark = 1;
    for(int i = 0 ; i < R; ++i)
    {
        for(int j = 0 ; j < C; ++j)
        {
            if(!visit[i][j])
            {
                dfs(i,j,mark);
                mark++;
            }
        }
    }
    memset(maxCol,0,sizeof(maxCol));

    for(int j = 0 ; j < C; ++j)
    {
        for(int i = 0 ; i < R; ++i)
        {
            maxCol[j] = max(maxCol[j],visit[i][j]);
        }
    }
    for(int i = 0 ; i < C; ++i)
    {
        stringstream ss;
        string s2;
        ss << maxCol[i];
        ss >> s2;
        maxCol[i] = s2.length();
    }
    for(int i = 0 ; i < R; ++i)
    {
        for(int j = 0 ; j < C; ++j)
        {
            if(j == 0)
            {
                cout << setw(maxCol[j]) << visit[i][j];
            }
            else
            {
                cout << setw(maxCol[j]+1) << visit[i][j];
            }
        }
        cout <<endl;
    }
    cout << "%" <<endl;
    return 0;
}
