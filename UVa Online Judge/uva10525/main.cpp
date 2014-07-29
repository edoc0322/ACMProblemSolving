#include <iostream>
#include <algorithm>

using namespace std;
int maps[505][505][2];
int N,M;
int main()
{
    int T;
    cin >> T;
    for(int t = 0 ; t < T ; ++t)
    {
        if(t > 0) cout << endl;
        cin >> N >> M;
        for(int i = 1 ; i <= N ; ++i)
        {
            for(int j = 1 ; j <= N ; ++j)
            {
                if(i == j) maps[i][j][0] = maps[i][j][1] = 0;
                else maps[i][j][0] = maps[i][j][1] = 1e9;
            }
        }
        int U,V,C,D;
        for(int i = 0 ; i < M ; ++i)
        {
            cin >> U >> V >> C >> D;
            if(C < maps[U][V][0])
            {
                maps[U][V][0] = maps[V][U][0] = C;
                maps[U][V][1] = maps[V][U][1] = D;
            }
            else if( C == maps[U][V][0])
            {
                if( D < maps[U][V][1])
                {
                    maps[U][V][1] = maps[V][U][1] = D;
                }
            }

        }
        for(int k = 1 ; k <= N; ++k)
        {
            for(int i = 1 ; i <= N ; ++i)
            {
                for(int j = 1 ; j <= N ; ++j)
                {
                    if(maps[i][j][0] > maps[i][k][0] + maps[k][j][0])
                    {
                        maps[i][j][0] = maps[i][k][0] + maps[k][j][0];
                        maps[i][j][1] = maps[i][k][1] + maps[k][j][1];
                    }
                    else if(maps[i][j][0] == maps[i][k][0] + maps[k][j][0])
                    {
                        if( maps[i][j][1] > maps[i][k][1] + maps[k][j][1])
                        {
                            maps[i][j][1] = maps[i][k][1] + maps[k][j][1];
                        }
                    }
                }
            }
        }


        int Q;
        cin >> Q;
        int u,v;
        while(Q--)
        {
            cin >>u >> v;
            if(maps[u][v][0] == 1e9)
            {
                cout << "No Path." <<endl;
            }
            else
            {
                cout << "Distance and time to reach destination is " <<
                maps[u][v][1] << " & " << maps[u][v][0] << "." <<endl;
            }
        }
    }
    return 0;
}
