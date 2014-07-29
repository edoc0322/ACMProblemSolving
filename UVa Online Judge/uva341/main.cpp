#include <iostream>

using namespace std;
int pre[101][101];
int d[101][101];
int N;
int main()
{
    int counts = 1;
    while(cin >> N && N)
    {
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                pre[i][j]= j;
                d[i][j] = 9999999;
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            d[i][i] = 0;
        }
        for(int i = 0 ; i < N;++i)
        {
            int n;
            cin >> n;
            for(int j = 0 ; j < n ; ++j)
            {
                int to,de;
                cin >> to >> de;
                d[i][to-1]  = de;

            }
        }
        for(int k = 0 ; k < N;++k)
        {
            for(int i = 0 ; i < N;++i)
            {
                for(int j = 0 ; j < N;++j)
                {
                    if(d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        pre[i][j] = pre[i][k];
                    }
                }
            }

        }

        int starts,ends;
        cin >> starts >> ends;
        cout << "Case "<< counts++ << ": Path =";
        for(int a = starts-1 ;a != ends-1; a = pre[a][ends-1])
        {
            cout << " " << a+1;
        }
        cout << " " <<ends ;
        cout << "; " << d[starts-1][ends-1] << " second delay" <<endl;

    }

    return 0;
}
