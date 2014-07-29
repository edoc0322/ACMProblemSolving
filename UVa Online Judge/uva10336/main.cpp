#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char maps[1000][1000];
int M,N;
bool v[1000][1000];
struct Eng
{
    int num;
    char c;
} ans[30];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool cmp(Eng a,Eng b)
{
    if(a.num > b.num)
    {
        return true;
    }
    else if(a.num < b.num)
    {
        return false;
    }
    else
    {
        return a.c < b.c;
    }
}

void dfs(int mark,int i,int j)
{
    v[i][j] = true;
    for(int m = 0 ; m < 4;++m)
    {
        int nx = j+dx[m];
        int ny = i+dy[m];
        if(ny >= 0 && ny < M && nx >=0 && nx < N && !v[ny][nx] && maps[ny][nx] == mark)
        {
            dfs(mark,ny,nx);
        }
    }
}

int main()
{
    int test;
    cin >> test;
    int c= 1;
    while(test--)
    {
        cin >> M;
        cin >> N;
        getchar();
        for(int i = 0 ; i < M;++i)
        {
            cin.getline(maps[i],1000);
            for(int j = 0 ; j < N;++j)
            {
                v[i][j] = false;
            }
        }
        for(int i = 0 ; i < 26;++i)
        {
            ans[i].num = 0;
            ans[i].c = ' ';
        }
        for(int i = 0 ; i < M;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                if(!v[i][j])
                {
                    dfs(maps[i][j],i,j);
                    ans[maps[i][j]-'a'].num++;
                    ans[maps[i][j]-'a'].c = maps[i][j];
                }
            }
        }
        sort(ans,ans+26,cmp);
        cout << "World #"<<c++ <<endl;
        for(int i = 0 ; i<26;++i)
        {
            if(ans[i].num>0)
            {
                cout << ans[i].c << ": " <<ans[i].num<<endl;
            }
            else
                break;
        }
    }
    return 0;
}
