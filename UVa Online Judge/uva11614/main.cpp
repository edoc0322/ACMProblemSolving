#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n ;
    double x;
    cin >> n;
    while(n > 0){
        cin >> x;
        cout << ((int)((-1 + sqrt(1 + 8*x)))>>1) << endl;
        n--;
    }
    return 0;
}
