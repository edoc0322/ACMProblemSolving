#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool v[51][51];
char maps[51][51];
int M,N;
int pn;
int maxI;
int tot;
struct pairs
{
    int num;
    char ch;
}pa[2501];

bool cmp(pairs a,pairs b)
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
        return a.ch < b.ch;
    }
}

void dfs(int mark,int i,int j)
{
    v[i][j] = true;
    for(int m = 0 ; m < 4;++m)
    {
        int nx = j + dx[m];
        int ny = i + dy[m];
        if(nx >=0 && nx < N && ny >=0 && ny < M && !v[ny][nx] && maps[ny][nx]==mark)
        {
            tot++;
            if(tot > maxI)
            {
                maxI = tot;
            }
            dfs(mark,ny,nx);
        }
    }
}

int main()
{
    int c = 1;
    while((cin >> M) && (cin >> N))
    {
        if(!M && !N) break;
        getchar();
        pn = 0;
        for(int i = 0 ; i < M;++i)
        {
            cin.getline(maps[i],1000);
            for(int j = 0 ; j < N;++j)
            {
                v[i][j] = false;
            }
        }

        for(int i = 0 ; i < M;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                if(!v[i][j] && maps[i][j] != '.')
                {
                    maxI = tot = 1;
                    dfs(maps[i][j],i,j);
                    pa[pn].ch = maps[i][j];
                    pa[pn].num = maxI;

                    pn++;
                }
            }
        }
        sort(pa,pa+pn,cmp);




        cout << "Problem " << c++ <<":"<<endl;
        for(int i = 0 ; i < pn;++i)
        {
            cout << pa[i].ch << " "<<pa[i].num<<endl;
        }
    }
    return 0;
}
