#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;
long long a[100000000];
int main()
{

    long long int counts;
    long long int x;
    while(cin  >> x)
    {
        getchar();
        string s;
        getline(cin,s);
        stringstream ss(s);
        counts = 0;
        long long temp;
        while(ss >> temp)
        {
            a[counts++] = temp;
        }
        long long n = counts-1;
        long long copyn = n;
        long long sums = 0;
        for(long long i = 0 ; i <= n-1; ++i)
        {
            sums = sums * x + a[i] * (copyn-i);
        }
        cout << sums<<endl;
    }
    return 0;
}
