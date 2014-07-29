#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
using namespace std;
int maps[25][25];
const int N = 20;
int main()
{
    int n;
    int test = 1;
    while(cin >> n)
    {
        for(int i = 1 ; i <= N;++i)
        {
            for(int j = 1 ; j <= N;++j)
            {
                if(i == j) maps[i][j] = 0;
                else maps[i][j] = 1e9;
            }
        }
        int v;
        for(int i = 0 ; i < n ; ++i)
        {
            cin >> v;
            maps[1][v] = maps[v][1] = 1;
        }
        for(int i = 2 ; i <= 19;++i)
        {
            cin >> n;
            for(int j = 0 ; j < n ; ++j)
            {
                cin >> v;
                maps[i][v] = maps[v][i] = 1;
            }
        }
        for(int k = 1 ; k <= N ; ++k)
        {
            for(int i = 1 ; i <= N;++i)
            {
                for(int j = 1 ; j <= N;++j)
                {
                    maps[i][j] = min(maps[i][j],maps[i][k] + maps[k][j]);
                }
            }
        }


        cout << "Test Set #" << test++ <<endl;
        int Q;
        cin >> Q;
        int p,q;
        while(Q--)
        {
            cin >> p >> q;
            //cout << setw(2) << p << " to " << setw(2) << q <<": " << setw(2) << maps[p][q] << endl;
            printf("%2d to %2d: %d\n", p, q, maps[p][q]);
        }
        cout <<endl;
    }
    return 0;
}
