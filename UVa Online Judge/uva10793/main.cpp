#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
int maps[105][105];
vector<int> total;
int main()
{
    int T;
    cin >> T;
    for(int t=  1 ; t <= T; ++t)
    {
        cin >> N >> M;
        for(int i = 1 ; i <= N ; ++i)
        {
            for(int j = 1 ; j <= N;++j)
            {
                if( i == j) maps[i][j] = 0;
                else maps[i][j] = 1e9;
            }
        }
        int U,V,C;
        for(int i = 0 ; i < M;++i)
        {
            cin >> U >> V >> C;
            maps[U][V] = min(C,maps[U][V]);
            maps[V][U] = maps[U][V];
        }
        /*
        for(int i = 1 ; i <= N ; ++i)
        {
            for(int j = 1 ; j <= N ; ++j)
            {
                cout << " " << maps[i][j] ;
            }
            cout <<endl;
        }
        */
        for(int k = 1 ; k <= N;++k)
            for(int i = 1 ; i <= N ; ++i)
                for(int j = 1 ; j <= N ;++j)
                    maps[i][j] = min(maps[i][j] , maps[i][k] + maps[k][j]);
        total.clear();
        /*
        for(int i = 1 ; i <= N ; ++i)
        {
            for(int j = 1 ; j <= N ; ++j)
            {
                cout << " " << maps[i][j] ;
            }
            cout <<endl;
        }
        */
        for(int i = 1; i<= N;++i)
        {
            int cur = maps[i][1];
            int status = 1;
            for(int j = 2 ; j <= 5 ; ++j)
            {
                if(maps[i][j] != cur || maps[i][j] == 1e9)
                {
                    //cout << "i  j  maps = " << i << "  " << j << "  " << maps[i][j] <<endl;
                    status = 0;
                    break;
                }
            }
            if(status)
            {
                //cout << "H! = " << i <<endl;
                total.push_back(i);
            }
        }
        int minD = 1e9,minI = 1;
        cout << "Map " << t << ": ";
        if(total.size() == 0)
        {
            cout << "-1" <<endl;
        }
        else
        {
            for(int i = 0 ; i < total.size() ;++i)
            {
                int curMaxD = -1;
                int status = 1;
                for(int j = 1 ; j <= N ;++j)
                {
                    if(maps[total[i]][j] == 1e9)
                    {
                        status = 0;
                        break;
                    }
                    if(maps[total[i]][j] > curMaxD)
                    {
                        curMaxD = maps[total[i]][j];
                    }
                }
                //cout << "cur MAx == " << curMaxD <<endl;
                if(status)
                {
                    minD = min(minD,curMaxD);
                }
            }
            if(minD == 1e9)
                cout << -1 <<endl;
            else
                cout << minD <<endl;
        }

    }
    return 0;
}
