#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;


int ansMatrix[5][5] = {{1,1,1,1,1},{0,1,1,1,1},{0,0,2,1,1},{0,0,0,0,1},{0,0,0,0,0}};
int maps[5][5];
int dx[8] = {2,2,1,-1,-2,-2,-1,1};
int dy[8] = {-1,1,2,2,1,-1,-2,-2};
int ans;
int ok;
void dfs(int x,int y,int depth)
{
    if(depth == ans)
    {
        int checks = 1;
        for(int i = 0 ; i < 5;++i)
        {
            for(int j = 0 ; j < 5;++j)
            {
                if(ansMatrix[i][j] != maps[i][j])
                {
                    checks = 0;
                    break;
                }
            }
            if(!checks) break;
        }
        if(checks)
        {
            ok = 1;
        }
        return;
    }
    if(ok) return;
    for(int i = 0  ; i < 8;++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
        {
            swap(maps[x][y],maps[nx][ny]);
            dfs(nx,ny,depth+1);
            if(ok) return;
            swap(maps[x][y],maps[nx][ny]);
        }

    }
}
int main()
{
    int test;
    cin >> test;
    getchar();
    char temps[10];
    while(test--)
    {
        int x,y;
        for(int i = 0 ; i < 5;++i)
        {
            cin.getline(temps,10);
            for(int j = 0 ; j < 5;++j)
            {
                if(temps[j] == '1')
                {
                    maps[i][j] = 1;
                }
                else if(temps[j] == '0')
                {
                    maps[i][j] = 0;
                }
                else
                {
                    maps[i][j] = 2;
                    x = i;
                    y = j;
                }
            }
        }
        ok = 0;
        for(ans = 0 ; ans <= 10;++ans)
        {
            dfs(x,y,0);
            if(ok) break;
        }
        if(ok)
        {
            cout << "Solvable in "<< ans << " move(s).\n";
        }
        else
        {
            cout << "Unsolvable in less than 11 move(s).\n";
        }
    }
    return 0;
}
