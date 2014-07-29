#include <iostream>

using namespace std;

int main()
{
    double H,U,D,F;
    while ( ( cin >> H ) &&( cin >> U ) &&( cin >> D ) && ( cin >> F ))
    {
        if(H==0 && U == 0 && D == 0 && F ==0){
            break;
        }
        double ans = 0;
        double fac = U * F/100;
        int count = 1;
        int status = 1;
        do
        {
            //cout << ans << "  " << U << " " << " " << count <<endl;
            if(U < 0){
                U = 0;
            }
            ans+=U;
            if(ans > H)
            {
               // cout << "Hi1"<<endl;
                cout << "success on day "<<count<<endl;;
                break;

            }
            ans -= D;
            if(ans <0){
                cout <<"failure on day "<<count<<endl;

                break;
            }
            U =  U-fac;


            count++;
        }while(1);


    }
    return 0;
}
