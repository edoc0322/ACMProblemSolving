#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long int maxI = (long long )1 << 31;
int main()
{
    //cout << maxI <<endl;
    vector<long long int> vec;
    long long int b2 = 1;
    long long int b3 = 1;
    for(int i = 1 ; ;++i)
    {
        for(int j = 1;;++j)
        {
            if(b2*b3 > maxI)break;
            vec.push_back(b2*b3);
            b3*=3;
        }
        //cout << b2 <<endl;
        b2*=2;
        b3 = 1;
        if(b2 > maxI)break;
    }
    sort(vec.begin(),vec.end());
    long long int N;
    while(cin >> N && N)
    {
        cout << *lower_bound(vec.begin(),vec.end(),N) <<endl;
    }
    return 0;
}
