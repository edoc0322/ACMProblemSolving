#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n>0){

        double b,h,r;
        double area,cir;
        cin >> b>>h;
        area = b*h/2;
        cir = sqrt(pow(b/2,2.0)+pow(h,2.0)) * 2 + b;
        r= 2*area /cir;
        double totcir = 0;
        double H2;
        while(r >= 0.000001)
        {
            totcir += 2 * M_PI * r;
            H2 = h - 2*r;
            r *= H2/h;
            h = H2;
        }
        cout << fixed << setw(13) << setprecision(6)<< totcir<<endl;
        if(n > 1){
            cout <<endl;
        }
        n--;
    }
    return 0;
}
