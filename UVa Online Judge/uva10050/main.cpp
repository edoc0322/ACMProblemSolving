#include <iostream>

using namespace std;

int main()
{
    int day[3665];
    int test;
    int d;
    int n;
    int s,i,j;
    int ans;
    cin >> test;
    while(test > 0){
        ans = 0;
        cin >> d;
        for(i = 1 ; i <= d;i++){
            day[i] = 0;
        }
        cin >> n;
        for(j = 0 ; j < n ;j++){
            cin >> s;
            for(i = 0 ; i <= d ;i+=s){
                day[i] = 1;
            }

        }
        for(i = 8 ; i <= d;i+=7){
            day[i-1] = day[i-2] = 0;
        }
        day[i-1] = day[i-2] = 0;
        for(i = 1 ; i <= d;i++){
            ans += day[i];
        }
        cout << ans << endl;
        test--;
    }
    return 0;
}
