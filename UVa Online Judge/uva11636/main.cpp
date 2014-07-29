#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int ans[10001];
    int i;
    int j = 0;
    for(i = 2 ; i*2 <= 50000;i*=2)
    {
        ans[j] = i;
        j++;
    }
    //cout << ans[0] << " " << ans[1]<<endl;
    int N;
    int c=1;
    while(cin >> N)
    {
        if(N < 0) break;
        if(N == 1) cout << "Case "<<c<<": "<< 0<<endl;
        else
            cout << "Case "<<c<<": "<< lower_bound(ans,ans+j,N)-ans + 1<<endl;;
        c++;

    }
    return 0;
}
