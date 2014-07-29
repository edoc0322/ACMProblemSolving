#include <iostream>

using namespace std;
long long int ans[101];
int main()
{
    ans[1] = 1;
    ans[2] = 5;
    ans[3] = 11;
    for(int i = 4 ; i <= 100;++i)
    {
        ans[i] = ans[i-1] + ans[i-2]*4 + ans[i-3]*2;
    }
    int t;
    cin >> t;
    int n;
    while(t--)
    {
        cin >> n;
        cout << ans[n] <<endl;
    }

    return 0;
}
