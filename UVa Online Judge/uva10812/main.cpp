#include <iostream>

using namespace std;

int main()
{
    int s , d,temp,temp2;
    int n ;
    cin >> n;
    while(n > 0){
        cin >> s ;
        cin >> d;
        int ans1 = (s+d)/2 , ans2 = (s-d)/2;
        if((s+d)%2 != 0 || ans2 < 0){
            cout << "impossible\n";
        }

        else
        {
            cout << ans1 << " " << ans2<<endl;
        }
        n--;
    }
    return 0;
}
