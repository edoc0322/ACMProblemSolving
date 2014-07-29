#include <iostream>

using namespace std;
int f[1001][301] = {};
int main()
{
    f[0][0] = 1;
    f[1][0] = 2;
    for(int i = 2 ; i <= 1000;++i)
    {
        for(int j = 0 ; j <300;++j)
        {
            f[i][j] += (f[i-1][j] + f[i-2][j]);
        }
        for(int j = 0 ; j < 300;++j)
        {
            f[i][j+1] += f[i][j] / 10;
            f[i][j] %= 10;
        }
    }
    int n;
    while(cin >> n)
    {
        int i = 300;
        while(f[n][i]==0)
        {
            i--;
        }
        for(int j = i ; j >= 0 ;--j)
        {
            cout << f[n][j];
        }
        cout << endl;
    }
    return 0;
}
