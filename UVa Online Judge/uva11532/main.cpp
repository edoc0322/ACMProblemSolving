#include <iostream>

using namespace std;
long long int bits[200];
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int P,Q;
        cin >> P >> Q;
        for(int i = 0 ; i < 200;++i)
        {
            bits[i] = 0;
        }
        int top = 0;
        while(P > 2*Q)
        {
            bits[top++] = 1;
            P--;
        }
        while(P > 1 && Q > 0)
        {
            bits[top++] = 1;
            bits[top++] = 0;
            bits[top++] = 1;
            P-= 2;
            Q--;
        }
        while(P > 0)
        {
            bits[top++] = 1;
            P--;
        }
        long long int ans = 0;
        long long int base = 1;
        for(int i = 0;i< top;++i)
        {
            ans += base*bits[i];
            base *= 2;
        }
        cout << ans <<endl;

    }
    return 0;
}
