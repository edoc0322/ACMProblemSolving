#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    double x[1001];
    double total;
    while(cin >> n){
        if(!n) break;
        total = 0;
        for(int i = 0 ; i < n ;i++){
            cin >> x[i];
            total += x[i];
        }
        double highx = (int)((total/n +0.0099)*100);
        double lowx = (int) (total/n*100);
        highx /= 100;
        lowx /= 100;
        double ans1 = 0,ans2 = 0;
        double ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(x[i] > highx){
                ans1 += x[i] - highx ;
            }
            else if (x[i] < lowx){
                ans2 +=  lowx - x[i];
            }
        }
        cout << "$"<<fixed << setprecision(2) << max(ans1,ans2) << endl;
    }
    return 0;
}
