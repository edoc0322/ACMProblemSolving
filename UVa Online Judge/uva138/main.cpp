#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int count = 0;
    long long int n2;
    long long int k = 6,k2;
    while(count != 10)
    {
        k2 = k*k*2;
        n2 = (long long int) sqrt(k2);
        if(k*k == n2*(n2+1)/2){
            cout << fixed<<setw(10) << k << fixed<<setw(10) << n2 << endl;
            ++count;
        }
        ++k;
    }
    return 0;
}
