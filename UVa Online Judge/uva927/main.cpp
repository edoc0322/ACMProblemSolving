#include <iostream>

using namespace std;
long long int c[10000];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n,d,k;
        cin >> n;
        for(int i = 0 ; i <= n;++i)
        {
            cin >> c[i];
        }
        cin >> d >> k;
        long long int index = 1;
        long long int d2 = 0;
        while(1)
        {
            d2 += index * d;
            if(d2 >= k)
            {
                break;
            }
            index++;
        }
        long long int sums = 0;
        for(int i = 0 ; i <= n;++i)
        {
            long long int bases = 1;
            for(int j = 0 ; j < i ;++j)
            {
                bases *= index;
            }
            sums += bases*c[i];
        }
        cout << sums <<endl;
    }
    return 0;
}
