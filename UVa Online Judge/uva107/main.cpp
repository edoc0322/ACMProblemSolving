#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double H,W;
    double N,k;
    double ans1,ans2;
    while((cin >> H) && (cin >> W))
    {
        if(H == 0 && W == 0) break;
        if(H == 1 && W == 1)
        {
            cout << "0 1\n";
            continue;
        }
        int status = 0;
        for(double i = 1;;i+=1.0)
        {
            for(double j = 1;;j+=1.0)
            {
                ans1 = pow(1+i,j);
                ans2 = pow(i,j);
                if(ans1 == H && ans2 == W){
                    status = 1;
                    N = i;
                    k = j;
                    break;
                }
                else if(ans1 > H || ans2 > W){
                    break;
                }
            }
            if(status)
            {
                break;
            }
        }
        double T = 0,HH = 0;
        for(double i=0.0; i <= k-1;i+=1.0)
        {
            T += pow(N,i);
            HH += pow(N,i) * H/pow(1+N,i);
        }
        HH += pow(N,k) * H / pow(1+N,k);
        cout << (int) T << " " << (int)HH<<endl;


    }
    return 0;
}
