#include <iostream>
#include <cstdio>
using namespace std;
int dx[6] = {-1,-1,0,1,1,0};
int dy[6] = {0,-1,-1,0,1,1};
char maps[205][205];
bool v[205][205];
int N;

int tot;
void dfs(int i,int j)
{
    v[i][j] = true;
    if(tot) return;
    if(i == N-1)
    {
        tot = 1;
        return ;
    }
    else
    {
        for(int m = 0 ; m < 6;++m)
        {
            int nx = j+dx[m];
            int ny = i+dy[m];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && maps[ny][nx] == 'b' && !v[ny][nx])
            {
                dfs(ny,nx);
                if(tot) return;
            }
            if(tot) return;
        }
        if(tot) return;
    }

}

int main()
{
    int c = 1;
    while(cin >> N)
    {
        if(!N) break;
        getchar();
        for(int i = 0 ; i < N;++i)
        {
            cin.getline(maps[i],1000);
            for(int j = 0 ; j < N;++j)
            {
                v[i][j] = false;
            }
        }
        char ans;
        for(int i = 0 ; i < N;++i)
        {
            tot = 0;
            if(!v[0][i])
                dfs(0,i);
            if(tot == 1)
            {
                break;
            }
        }




        cout << c << " ";
        if(tot)
            cout << "B" <<endl;
        else
            cout << "W" <<endl;
        c++;
    }


    return 0;
}
