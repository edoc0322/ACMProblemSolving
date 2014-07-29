#include <iostream>
#include <algorithm>
using namespace std;
int maps[105][105];
int main()
{
    int T;
    cin >> T;
    for(int t = 1 ; t <= T;++t)
    {
        int N,M;
        cin >> N >> M;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                if(i != j)
                    maps[i][j] = 1e9;
                else
                    maps[i][j] = 0;
            }
        }
        int u,v;
        for(int i = 0 ; i < M;++i)
        {
            cin >> u >> v;
            maps[u][v] = maps[v][u] = 1;
        }
        int s,t2 ;
        cin >> s>> t2;
        for(int k = 0 ; k < N;++k)
        {
            for(int i = 0 ; i < N ; ++i)
            {
                for(int j = 0 ; j < N;++j)
                {
                    maps[i][j] = min(maps[i][j] , maps[i][k] + maps[k][j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < N;++i)
        {
            ans = max(ans,maps[s][i] + maps[i][t2]);
        }
        cout << "Case " << t << ": " << ans <<endl;
    }
    return 0;
}
