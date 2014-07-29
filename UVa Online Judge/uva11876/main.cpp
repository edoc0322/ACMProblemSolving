#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long num[1000005];
long long int nod(long long int x)
{
    long long int counts = 0;
    for(long long y = 1;y <= sqrt((double)x);++y)
    {
        if(y == 0 )break;
        if(x % y == 0)
        {
            if(x / y == y)
            {
                counts++;
            }
            else
            {
                counts+= 2;
            }
        }
    }
    return counts;
}
int main()
{
    num[0] = 1;
    int i;
    for(i = 1 ; i <= 1000000;++i)
    {
        num[i] = num[i-1] + nod(num[i-1]);
        if(num[i] > 1000000)break;
        //cout << num[i] <<endl;
    }
    int test;
    cin >> test;
    for(int t = 1 ;t <= test;++t)
    {
        cout << "Case " << t << ": ";
        long long a,b;
        cin >> a >> b;
        cout << (upper_bound(num,num+i,b)-lower_bound(num,num+i,a)) <<endl;
    }
    return 0;
}
