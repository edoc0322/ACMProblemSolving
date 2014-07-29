#include <iostream>

using namespace std;


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int m,n;
        cin >> m;
        cin >> n;
        int ans = 1;
        ans *= (m/3);
        ans *= (n/3);
        cout <<ans<<endl;
    }
    return 0;
}
