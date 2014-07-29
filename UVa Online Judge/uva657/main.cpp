#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char maps[100][100];
int v[100][100];
int M,N;
int tot;
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int dx2[4] = {1,0,-1,0};
int dy2[4] = {0,1,0,-1};
vector<int> ans;
void dfs2(int y,int x);
void dfs(int i ,int j);

int ori;

int main()
{
    int c = 1;
    while((cin >> N) && (cin >> M))
    {
        if(!M && !N) break;
        getchar();
        for(int i = 0 ; i < M;++i)
        {
            cin.getline(maps[i],1000);
            for(int j = 0 ; j < N;++j)
            {
                v[i][j] = 0;
            }
        }
        ans.clear();
        for(int i = 0 ; i < M;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                int status = 0;
                if(!v[i][j] && (maps[i][j] == '*' || maps[i][j] == 'X'))
                {
                    dfs(i,j);
                    status = 1;
                }
                if(status)
                {
                    tot = 0;
                    for(int m = 0 ; m < M ;++m)
                    {
                        for(int p = 0 ; p < N ;++p)
                        {
                            if(v[m][p] == 2 && maps[m][p] == 'X')
                            {
                                dfs2(m,p);
                                tot++;
                            }
                        }
                    }
                    ans.push_back(tot);
                }

            }
        }



        cout << "Throw "<<c++<<endl;
        if(ans.empty())
        {
            cout <<0<< endl;
            cout <<endl;
            continue;
        }

        sort(ans.begin(),ans.end());
        for(int i = 0 ; i < ans.size();++i)
        {
            if(i == 0)
                cout << ans[i];
            else
                cout << " " << ans[i];
        }
        cout << endl;
        cout <<endl;

    }
    return 0;
}



void dfs(int i,int j)
{
    if(maps[i][j] == '*')
    {
        v[i][j] = 1;
    }
    else if(maps[i][j] == 'X')
    {
        v[i][j] = 2;
    }
    for(int m = 0; m < 4;++m)
    {
        int ny = i + dy2[m];
        int nx = j + dx2[m];
        if(ny >= 0 && ny < M && nx >= 0 && nx < N && !v[ny][nx])
        {
            if(maps[ny][nx] == '*')
            {
                dfs(ny,nx);
            }
            else if(maps[ny][nx] == 'X')
            {
                dfs(ny,nx);
            }
        }
    }
}

void dfs2(int y,int x)
{
    v[y][x] = 3;
    for(int m = 0; m < 4;++m)
    {
        int ny = y + dy2[m];
        int nx = x + dx2[m];
        if(ny >= 0 && ny < M && nx >= 0 && nx < N && v[ny][nx] == 2)
        {
            if(maps[ny][nx] == 'X')
            {
                dfs2(ny,nx);
            }
        }
    }

}
