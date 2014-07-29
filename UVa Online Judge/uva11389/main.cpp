#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,d,r;
int mor[105];
int eve[105];
int main()
{
    while(cin >> n && cin >> d && cin >> r)
    {
        if(!n&&!d&&!r) break;
        for(int i = 0 ; i < n;++i)
        {
            cin >> mor[i];
        }
        for(int i = 0 ; i < n;++i)
        {
            cin >> eve[i];
        }
        sort(mor,mor+n);
        sort(eve,eve+n, greater<int>() );
        int sums = 0;
        for(int i = 0 ; i < n;++i)
        {
            if(mor[i]+eve[i] > d)
            {
                sums += (mor[i]+eve[i]-d)*r;
            }
        }
        cout << sums <<endl;
    }
    return 0;
}
