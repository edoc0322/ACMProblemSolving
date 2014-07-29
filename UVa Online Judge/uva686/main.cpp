#include <iostream>
bool prime[1000001];

void eratosthenes()
{
    for (int i=0; i<1000001; i++)  // ﹍て
        prime[i] = true;

    prime[0] = false;   // 0 ㎝ 1 ぃ琌借计
    prime[1] = false;

    // тゼ砆奔计
    for (int i=2; i<1000001; i++)
        if (prime[i])
            // 奔借计i计眖ㄢ秨﹍玂痙セ借计
            for (int j=i+i; j<1000001; j+=i)
                prime[j] = false;
}
using namespace std;

int main()
{
    eratosthenes();
    int n;
    while(cin >> n){
        if(!n) break;
        int hn = n/2;
        int ans = 0;
        for(int i = 2 ;i <= n;i++){
            if(i > hn){
                break;
            }
            if(prime[i] && prime[n-i]){
                ans++;
            }
        }
        cout << ans<<endl;
    }
    return 0;
}
