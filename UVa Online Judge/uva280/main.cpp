#include <iostream>
#include <stdio.h>
using namespace std;

int maps[110][110];
int v[110];
int N;
int status;
int counts;

void dfs(int s)
{
    if(status == 1)
    {
        status = 0;
    }
    else
    {
        v[s] = 1;
    }
    for(int i = 1 ; i <= N;++i)
    {
        if(maps[s][i] == 1 && v[i] == 0)
        {
            //cout << s << " " << i << endl;
            dfs(i);
        }
    }
}


int main()
{

    while(cin >> N && N)
    {
        for(int i = 1 ; i <= N;++i)
        {
            v[i] = 0;
            for(int j = 1 ; j <= N;++j)
            {
                maps[i][j] = 0;
            }
        }

        int k,k2;

        while(cin >> k)
        {
            if(k == 0) break;
            counts = k;
            while(cin >> k2)
            {
                if(k2 == 0) break;
                maps[counts][k2] = 1;
            }

        }



        int test;
        int start;
        cin >> test;
        {
            for(int i = 0 ; i < test;++i)
            {
                cin >> start;
                status = 1;
                for(int i = 1 ; i <= N;++i)
                {
                    v[i] = 0;
                }
                dfs(start);
                int sums = 0;

                for(int i = 1 ; i <= N;++i)
                {
                    if(v[i] == 0)
                    {
                        sums++;
                    }
                }

                cout << sums;
                for(int i = 1 ; i <= N;++i)
                {
                    if(v[i] == 0)
                    {
                        cout << " " << i ;
                    }
                }
                cout <<endl;
            }
        }
    }

    return 0;
}
