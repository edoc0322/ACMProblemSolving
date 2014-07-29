#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double p,q,r,s,t,u;
    while(cin >> p  >> q >> r >> s >> t >> u)
    {
        double right = 1.0,left = 0.0,mid,ans;
        for(int i = 0 ; i < 100;++i)
        {
            mid = (right+left)/2;
            ans = p*exp(-mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*pow(mid,2) + u;
            if(ans > 0)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
            //cout << ans <<endl;
        }
        if(fabs(p*exp(-mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*pow(mid,2) + u-0) <= 1e-10)
        {
            cout << fixed << setprecision(4) << mid <<endl;

        }
        else
        {
            cout << "No solution" <<endl;
        }
    }
    return 0;
}
