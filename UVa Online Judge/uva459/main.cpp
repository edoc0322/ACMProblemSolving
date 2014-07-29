#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int maps[27][27];
int vertex[27];
char name[31];
int maxN;



void dfs(int i)
{
    vertex[i] = 0;
    for(int j = 0 ; j < maxN;++j)
    {
        if(maps[i][j] && vertex[j])
        {
            dfs(j);
        }
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    getchar();
    int c =0;
    while(test > 0)
    {
        while(gets(name) && *name)
        {
            if(strlen(name) == 1)
            {
                maxN = name[0]-'A' + 1;
                for(int i = 0 ; i < maxN ;++i)
                {
                    vertex[i] = 1;
                    for(int j = 0 ; j < maxN;++j)
                    {
                        maps[i][j] = 0;
                    }
                }
            }
            else
            {
                int x = name[0]-'A';
                int y = name[1]-'A';
                maps[x][y] = maps[y][x] = 1;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < maxN;++i)
        {
            if(vertex[i])
            {
                dfs(i);
                ans++;
            }
        }
        if(c > 0)
        {
            cout << endl;
        }
        cout << ans <<endl;
        c++;


        test--;
    }
    return 0;
}
