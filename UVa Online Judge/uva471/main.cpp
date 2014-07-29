#include <iostream>

using namespace std;
long long int N,s2,s1;
long long int findAns(long long int n1,long long int n2)
{
    int v[10] = {};
    int v2[10] = {};
    long long int n3 = n1 * n2;
    long long int n5 = n1;
    if(n3 >= 10000000000)
    {
        return n3;
    }
    long long int n4 = n3;
    while(n1)
    {
        if(v2[n1%10])return 0;
        v2[n1%10] = 1;
        n1/= 10;
    }
    while(n3)
    {
        if(v[n3%10])return 0;
        v[n3%10] = 1;
        n3 /= 10;
    }
    return n4;
}
int main()
{
    int t;
    cin >> t;
    int counts = 0;
    while(t--)
    {
        if(counts > 0)
        {
            cout << endl;
        }
        cin >> N;
        for(long long int i = 1 ; ;++i)
        {
            long long int ans = findAns(i,N);
            if(ans >= 10000000000)
            {
                break;
            }
            if(ans != 0)
            {
                cout << ans << " / " << i << " = " << N <<endl;
            }
        }
        counts++;
    }

    return 0;
}
