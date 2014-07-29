#include <iostream>
#include <cmath>
using namespace std;

int maps[1000][1000];
int d[1000][1000];
int v[1000][1000];
int M,N;

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> M;
        cin >> N;
        for(int i = 0 ;i < M;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cin >> maps[i][j];
                d[i][j] = 1e9;
                v[i][j] = 0;
            }
        }
        d[0][0] = maps[0][0];
        for(int k = 0 ; k < M*N;++k)
        {
            int a[2] = {-1,-1};
            int minI = 1e9;
            for(int i = 0 ;i < M;++i)
            {
                for(int j = 0 ; j < N;++j)
                {
                    if(!v[i][j] && d[i][j] < minI)
                    {
                        minI = d[i][j];
                        a[0] = i;
                        a[1] = j;
                    }
                }
            }
            if(a[0] == -1 && a[1] == -1 )break;
            v[a[0]][a[1]] = 1;
           //cout << a[0] << " " << a[1] << " " << d[a[0]][a[1]]<<endl;
            for(int i = 0 ; i < M;++i)
            {
                for(int j = 0 ; j< N;++j)
                {
                    if(!v[i][j] && (i-a[0] == 1 && j-a[1] == 0 || i-a[0] == 0 && j-a[1] == 1 || i-a[0] == -1 && j-a[1] == 0 || i-a[0] == 0 && j-a[1] == -1)
                       && d[a[0]][a[1]] + maps[i][j] < d[i][j] )
                    {
                        //cout << "i j " << i << " " << j <<endl;
                        d[i][j] = d[a[0]][a[1]] + maps[i][j];

                    }
                }
            }
        }
        cout << d[M-1][N-1] <<endl;


    }

    return 0;
}
