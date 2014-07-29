#include <iostream>
#include <queue>
#define inf 1000000000
using namespace std;


int d[1001];
int maps[1001][1001];
int N;
int D;
void bfs()
{
    queue<int> que;
    que.push(0);
    for(int i = 0 ; i < N;++i)
    {
        d[i] = inf;
    }
    d[0] = 0;
    while(que.size())
    {
        int p = que.front();
        que.pop();
        for(int i = 0 ; i < N;++i)
        {
            if(maps[p][i] && d[i] > d[p] + 1)
            {
                d[i] = d[p] + 1;
                que.push(i);
            }
        }
    }
}

int main()
{
    int test;

    cin >> test;
    int blank = 0;
    while(test--)
    {
        if(blank) cout << endl;
        blank = 1;
        cin >> N;
        cin >> D;
        int a,b;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = 0;
            }
        }
        for(int i = 0 ; i < D;++i)
        {
            cin >> a;
            cin >> b;
            maps[a][b] = maps[b][a] = 1;
        }
        bfs();
        for(int i = 1 ;i < N;++i)
        {
            cout << d[i]<<endl;
        }
    }
    return 0;
}
