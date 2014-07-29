#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int test ;
    cin >> test;
    double ff,pff;
    while(test>0){
        cin >> ff;
        cin >> pff;
        cout.setf(ios::fixed);
        cout.precision(3);
        cout << M_PI*(pff/2)*sqrt((pff/2)*(pff/2)- (ff/2)*(ff/2)) << endl;
        test--;
    }
    return 0;
}
