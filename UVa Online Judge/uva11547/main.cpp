#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int N;
    while(T--)
    {
        cin >> N;
        int temp = N;
        temp = ((temp * 63 + 7492) * 5) - 498;
        int re = (temp / 100)*100;
        int ans = abs((temp - re)/10);
        cout << ans <<endl;
    }
    return 0;
}
