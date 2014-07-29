#include <iostream>
#include <string>
using namespace std;
bool prime[15000];

void eratosthenes()
{
    for (int i=0; i<15000; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = true;


    for (int i=2; i<15000; i++)
        if (prime[i])
            for (int j=i+i; j<15000; j+=i)
                prime[j] = false;
}
int main()
{
    eratosthenes();
    string s;
    while(cin >> s){
        int ans = 0;
        for(int i = 0 ; i < s.length();i++){
            if(s[i]>='a' && s[i] <= 'z'){
                ans += ((int)(s[i]-'a')+1);
            }
            else{
                ans += ((int)(s[i]-'A')+27);
            }
        }

        if(prime[ans]){
            cout << "It is a prime word.\n";
        }
        else{
            cout << "It is not a prime word.\n";
        }
    }
    return 0;
}
