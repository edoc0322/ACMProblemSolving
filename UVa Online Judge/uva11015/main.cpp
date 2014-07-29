#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N,M;
string names[100];
int maps[100][100];
int main()
{
    int test = 1;
    while(cin >> N >> M && N+M)
    {
        for(int i = 1 ; i <= N ;++i)
        {
            cin >> names[i];
        }
        for(int i = 1 ; i <= N;++i)
        {
            for(int j = 1 ; j <= N; ++j)
            {
                if(i == j) maps[i][j] = 0;
                else maps[i][j] = 1e9;
            }
        }
        int U,V,C;
        for(int i = 0 ; i < M; ++i)
        {
            cin >> U >> V >> C;
            maps[U][V] = maps[V][U] = C;
        }
        for(int k = 1 ; k <= N ;++k)
        {
            for(int i = 1 ; i <= N;++i)
            {
                for(int j = 1 ; j <= N; ++j)
                {
                    maps[i][j] = min(maps[i][j],maps[i][k] + maps[k][j]);
                }
            }
        }
        int minCost = 1e9,minIndex = -1;
        for(int i = 1 ; i  <= N;++i)
        {
            int sums = 0;
            for(int j = 1 ; j <= N;++j)
            {
                sums += maps[i][j];
            }
            if(sums < minCost)
            {
                minCost = sums;
                minIndex = i;
            }
        }
        cout << "Case #" << test++ << " : " << names[minIndex] <<endl;

    }
    return 0;
}
