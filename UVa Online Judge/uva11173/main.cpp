#include <iostream>

using namespace std;

int main()
{
    int test;
    int n,k;
    cin >> test;
    while(test--)
    {
        cin >> n >> k;
        cout << (k^(k >> 1 )) <<endl;
    }
    return 0;
}
