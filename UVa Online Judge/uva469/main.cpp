#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

char maps[100][100];
bool v[100][100];
int M,N;
int num[1000][2];
int nn = 0;
int tot;
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int maxI;
void dfs(int i ,int j)
{
    v[i][j] = true;
    for(int m = 0 ; m < 8;++m)
    {

        int nx = j+dx[m];
        int ny = i + dy[m];
        if(nx >= 0 && nx < N&&ny >=0 && ny < M && maps[ny][nx] == 'W' && !v[ny][nx])
        {
            tot++;
            if(tot > maxI)
            {
                maxI = tot;
            }
            //cout << ny << " " << nx<<endl;
            dfs(ny,nx);
        }
    }
}

int main()
{
    int test ;
    cin >> test;
    getchar();
    getchar();
    M = 0;
    int c=0;
    char temp[1000];
    while(test--)
    {
        while(gets(temp) && *temp)
        {
            if(temp[0] == 'L' || temp[0]=='W')
            {
                strcpy(maps[M],temp);
                M++;
            }
            else
            {
                char *t = strtok(temp," ");
                char *t2 = strtok(NULL," ");
                num[nn][0] = atoi(t);
                num[nn][1] = atoi(t2);
                nn++;
            }
        }
        N = strlen(maps[0]);
        if(c > 0)
        {
            cout <<endl;
        }
        for(int i = 0 ; i < nn;++i)
        {
            for(int j = 0 ; j< M;++j)
            {
                for(int k = 0 ; k < N;++k)
                {
                    v[j][k] =false;
                }
            }
            tot = 0;
            maxI = 0;
            dfs(num[i][0]-1,num[i][1]-1);
            cout << maxI+1<<endl;
        }


        c++;
        M = 0;
        nn=0;
    }
    return 0;
}
