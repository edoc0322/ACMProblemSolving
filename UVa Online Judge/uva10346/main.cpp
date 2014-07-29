#include <iostream>

using namespace std;

int main()
{
    int n ,k;
    int ans;
    while((cin >> n) && (cin >> k)){
        ans = 0;
        int butt = 0;
        while(n>0){
            ans += n;
            butt += n;
            n = butt/k;
            butt = butt %k;

        }
        cout << ans<<endl;
    }
    return 0;
}
