#include <iostream>

using namespace std;
bool isprime(int n)
{
    for (int i=2; i*i<=n; i++)
        if (n%i == 0)
            return false;
    return n != 1;
}
int prime[1000002];
int digiprime[1000002];
int main()
{
    int test;
    prime[1] = 0;
    prime[2] = 1;
    int ans = 0;
    int temp;
    for(int i = 3 ; i <= 1000000;i++){
        if(isprime(i)){
            prime[i] = 1;
        }
        else{
            prime[i] = 0;
        }
    }
    digiprime[1] = 0;
    for (int i= 2;i<= 1000000;i++){
        ans = 0;
        temp = i;
        while(temp){
            ans += temp % 10;
            temp = temp /10;
        }
        //cout << "ans " << ans << endl;

        digiprime[i] = digiprime[i-1] + (prime[ans] & prime[i]);
    }
    digiprime[0] = 0;
    cin >> test;
    int n1,n2;
    while(test>0){
        cin >> n1;
        cin >> n2;
        ans = 0;

        cout << digiprime[n2] - digiprime[n1-1]<<endl;

        test--;
    }
    return 0;
}
