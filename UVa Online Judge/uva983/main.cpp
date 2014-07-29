#include <iostream>

using namespace std;

int N,M;
long long int maps[1005][1005];

long long int findSum(int sx,int sy,int ex,int ey)
{
    long long int sums = maps[ey][ex];
    if(sx >= 1)
    {
        sums -= maps[ey][sx-1];
    }
    if(sy >= 1)
    {
        sums -= maps[sy-1][ex];
    }
    if(sx >= 1 && sy >= 1)
    {
        sums += maps[sy-1][sx-1];
    }
    return sums;
}
int main()
{
    int t = 0;
    while(cin >> N && cin >> M)
    {
        if(t > 0) cout <<endl;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < N;++j)
            {
                cin >> maps[i][j];
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 1 ; j < N;++j)
            {
                maps[i][j] += maps[i][j-1];
            }
        }

        for(int i = 0 ; i < N;++i)
        {
            for(int j = 1 ; j < N;++j)
            {
                maps[j][i] += maps[j-1][i];
            }
        }
        long long int sums = 0;
        for(int i = 0 ; i < N-M+1;++i)
        {
            for(int j = 0 ; j < N-M+1;++j)
            {
                long long int ans = findSum(j,i,j+M-1,i+M-1);
                cout << ans <<endl;
                sums += ans;
            }
        }
        cout << sums <<endl;
        t++;
    }
    return 0;
}
