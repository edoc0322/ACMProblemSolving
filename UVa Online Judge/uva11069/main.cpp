#include <iostream>

using namespace std;

int main()
{
    int f[77];
    f[1] = 1;
    f[2] = f[3] = 2;
    f[4] = 3;
    for(int i = 5;i<=76;++i)
    {
        f[i] = f[i-2] + f[i-3];
    }
    int t;
    while(cin >> t)
    {
        cout << f[t]<<endl;
    }
    return 0;
}
