#include <iostream>

using namespace std;
int ans[10];
int v[10][10];
int maps[10][10];
int mark[10][10];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1}  };

void dfs(int index,int x,int y,int N)
{
    v[y][x] = 1;
    ans[index] += maps[y][x];
    for(int i = 0 ; i < 4;++i)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx >= 0 && nx < N && ny >= 0 && ny < N && v[ny][nx] == 0 && mark[ny][nx] == index)
        {
            dfs(index,nx,ny,N);
        }
    }
}
int main()
{
    int N;

    int test = 1;
    while(cin >> N && N)
    {
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j<N;++j)
            {
                cin >> maps[i][j];
                v[i][j] = 0;
            }
        }
        //cout << N;
        int maxI = 0;
        int mid = (N % 2 == 1)? (N/2 + 1) : (N/2);
        for(int i = 0 ; i < mid; ++i)
        {
            for(int j = 0 ; j < mid;++j)
            {
                if(j < maxI)
                {
                    mark[i][j] = j;
                    mark[N-i-1][j] = j;
                    mark[i][N-j-1] = j;
                    mark[N-i-1][N-j-1] = j;
                }
                else
                {
                    mark[i][j] = maxI;
                    mark[N-i-1][j] = maxI;
                    mark[i][N-j-1] = maxI;
                    mark[N-i-1][N-j-1] = maxI;
                }
            }
            maxI++;
        }
        for(int i = 0 ;i < maxI;++i)
        {
            ans[i] = 0;
            dfs(i,i,i,N);
        }
        cout << "Case " << test++ << ":";
        for(int i = 0 ; i < maxI;++i)
        {
            cout << " "<<ans[i];
        }
        cout << endl;

    }
    return 0;
}
