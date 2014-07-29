#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> primes;
bool allP[10000000];
int main()
{
    memset(allP,1,sizeof(allP));
    for(int i = 2 ; i <=2000000 ;++i)
    {
        if(allP[i])
        {
            primes.push_back(i);
            for(int k = i+i;k <= 2000000 ;k+=i)
            {
                allP[k] = 0;
            }
        }
    }
    int N;
    int test = 1;
    while(cin >> N && N)
    {
        cout << "Case " << test++ << ": ";
        long long int counts = 0;
        for(int i = 0 ; ;++i)
        {
            if(primes[i]>N/2) break;
            int cut = N-primes[i];
            int idx = upper_bound(primes.begin(),primes.end(),cut)- (primes.begin())-1;
            idx -= i;
            //cout << idx << "   " << cut <<endl;
            counts += idx;
        }
        cout << counts <<endl;
    }
    return 0;
}
