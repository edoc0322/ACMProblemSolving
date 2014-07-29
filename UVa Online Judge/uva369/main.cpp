#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double n,m,maxm,minm;
    long long int i , j ;
    while(cin >> n){
        cin >> m;
        if(n == 0 && m == 0 )break;
        if(n-m > m){
            maxm = n-m;
            minm = m;
        }
        else{
            maxm = m;
            minm = n-m;
        }
        double ans = 1;
        j = 1;
        for(i = 1 ; i <= n ; i++){
            if(j > maxm) break;
            ans = ans * i/j;
            j++;
        }
        j = 1;
        for(;i<=n;i++){
            if(((int)ans*i)%j == 0){
                ans = (ans*i/j);
                j++;
                if(j > minm){
                    j = 1;
                    minm = 0;
                }
            }
            else{
                ans *= i ;
            }
        }
        cout << n <<" things taken " << m <<" at a time is ";
        cout << fixed << setprecision(0)<< ans ;
        cout << " exactly.\n";

    }
    return 0;
}
