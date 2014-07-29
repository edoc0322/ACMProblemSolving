#include <iostream>
#include <queue>
#define inf 10000000
using namespace std;

const int maxN = 2501;
int N;
int d[maxN];
int maps[maxN][maxN];

int maxA[maxN];
int M,D;

void finds(int s)
{
    D = 0;
    M = 0;
    for(int i = 0 ; i < N;++i)
    {
        maxA[i] = 0;
    }
    for(int i = 0 ; i < N;++i)
    {
        if(s != i )
        {
            if(d[i] != inf)
                maxA[d[i]]++;
        }
    }
    for(int i = 0 ; i < N;++i)
    {
        if(maxA[i] > M)
        {
            M = maxA[i];
            D = i;
        }
    }

}

void bfs(int s)
{
    queue<int> que;
    for(int i = 0 ;i < N;++i)
    {
        d[i] = inf;
    }
    d[s] = 0;
    que.push(s);
    while(que.size())
    {
        int p = que.front();
        que.pop();
        for(int i = 0 ;i < N;++i)
        {
            if(maps[p][i] && d[i] > d[p]  + 1)
            {
                d[i] = d[p] + 1;
                que.push(i);
            }
        }
    }
}

int main()
{
    while(cin >> N)
    {
        int c;
        int c2;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                maps[i][j] = 0;
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> c;
            for(int j = 0 ; j < c;++j)
            {
                cin >> c2;
                maps[i][c2] = 1;
            }
        }
        int test;
        cin >> test;
        while(test--)
        {
            int source;
            cin >> source;
            bfs(source);
            finds(source);
            if(!M)
            {
                cout << 0 <<endl;
            }
            else
            {
                cout << M << " " << D <<endl;
            }

        }
    }
    return 0;
}
