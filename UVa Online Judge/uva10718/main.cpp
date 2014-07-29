#include <iostream>

using namespace std;

int main()
{
    long long N,L,U;
    while(cin >> N && cin >> L && cin >> U)
    {
        long long ans = 0;
        for(long long int base = (long long)1 << 31;base> 0;base = base>>1)
        {
            if(ans < L && (L&base))
            {
                ans |= base;
                continue;
            }
            if( (ans|base) >= L && (ans|base) <= U)
            {
                if( (N & base) == 0)
                {
                    ans |= base;
                }
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
