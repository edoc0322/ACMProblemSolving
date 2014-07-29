#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int test;
    cin >> test;
    int i,n;
    double p;
    while(test--)
    {
        cin >> n >> p >> i ;
        if(1 - p == 1 )
        {
            cout << "0.0000" <<endl;
        }
        else
            cout << fixed << setprecision(4) << (p* pow(1-p,i-1)) / (1 - pow(1-p,n)) <<endl;
    }
    return 0;
}
