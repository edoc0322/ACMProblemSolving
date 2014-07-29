#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double n,p;
    while((cin >> n ) && (cin >> p))
    {
        double k;
        k = pow(10.0,log10(p)/n);
        cout << fixed << setprecision(0)<<k <<endl;

        /*
        for(k = 1.0;;k+=1.0)
        {
            //cout << k<<endl;
            double ans = k;
            int temp;
            for(int i = 0 ; i < n;++i)
            {
                ans *= ans;
                temp =  ans;
                ans = temp;
            }
            cout << ans << endl;
            if(fabs(ans- p) < 1e-9)
            {
                cout << (int) k <<endl;
                break;
            }
        }
        */
    }
    return 0;
}
