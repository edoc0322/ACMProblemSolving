#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int v[200];
bool prime[20000001];
void sieve()
{
    for(int i = 0 ; i < 20000000;++i)
    {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for(int i = 2 ; i < 20000000;++i)
    {
        if(prime[i])
        {
            for(int j = i*2; j < 20000000; j+=i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    sieve();
    int test;
    cin >> test;
    int counts = 1;
    while(test--)
    {
        string s;
        cin >> s;
        for(int i = 0 ; i<200;++i)
        {
            v[i] = 0;
        }
        for(int i = 0 ; i < s.length() ; ++i )
        {
            v[s[i]]++;
        }
        string ans = "";

        for(int i = '0' ; i <= '9';++i)
        {
            if(prime[v[i]])
            {
                char temp[2];
                temp[0] = (char) i;
                temp[1] = '\0';
                ans += string(temp);
            }
        }

        for(int i = 'A' ; i <= 'Z';++i)
        {
            if(prime[v[i]])
            {
                char temp[2];
                temp[0] = (char) i;
                temp[1] = '\0';
                ans += string(temp);
            }
        }

        for(int i = 'a' ; i <= 'z';++i)
        {
            if(prime[v[i]])
            {
                char temp[2];
                temp[0] = (char) i;
                temp[1] = '\0';
                ans += string(temp);
            }
        }
        cout << "Case " <<counts++ <<": ";
        if(ans == "")
        {
            cout << "empty" <<endl;
        }
        else
        {
            sort(ans.begin(),ans.end());
            cout << ans << endl;
        }
    }
    return 0;
}
