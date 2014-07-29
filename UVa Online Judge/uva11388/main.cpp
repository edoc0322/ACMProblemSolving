#include <iostream>

using namespace std;

int main()
{
    long long int a,b;
    int test;
    cin >> test;
    while(test--)
    {
        cin >> a >> b;
        if(b %a == 0)
        {
            cout << a << " " << b <<endl;
        }
        else
        {
            cout << "-1" <<endl;
        }
    }

    return 0;
}
