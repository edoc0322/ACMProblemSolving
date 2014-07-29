#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int test;
    cin >> test;
    int tt,num;
    int tnum;
    int ans1,ans2;
    while(test > 0){
        cin >> tt;
        cin >> num;
        tnum = num;
        ans1 = 0;
        while(tnum){
            ans1 += tnum&1 ;
            tnum = tnum >> 1;
        }
        ans1 += 1;
        tnum = num;

        cout << ans1 << " ";
        tt = 1 << tt;

        int temp = (num == 0) ? (tt) : (num&-num);
        cout << (tt - temp + 1) << endl;
        //cout << "m&-m " << (num) << " " <<(-num) << endl;
        test--;

    }
    return 0;
}
