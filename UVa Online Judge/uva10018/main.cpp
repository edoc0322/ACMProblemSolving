#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s1;
        string s2;
        cin >> s1;
        long long int ans = 0;
        int ok=1;
        do
        {
            ok=1;
            for(int i = 0 ; i < s1.length()/2+1;++i)
            {
                if(s1[i] != s1[s1.length()-1-i])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) break;
            ans++;
            s2.resize(s1.length());
            for(int i = 0 ; i < s1.length();++i)
            {
                s2[s1.length()-i-1]=s1[i];
            }

            long long int a = 0,b = 0;
            long long int base = 1;
            for(int i = s1.length()-1 ; i >=0;--i)
            {
                a += base*(s1[i]-'0');
                b += base*(s2[i]-'0');
                base*=10;
            }
            long long int total = a+b;
            long long int temp =total;
            long long int sizes = 0;
            while(temp != 0)
            {
                temp /= 10;
                sizes++;
            }
            s1.resize(sizes);
            for(int i = s1.length()-1;i>=0;--i)
            {
                s1[i] = (total % 10)+'0' ;
                total /= 10;
            }

        }while(!ok);
        cout << ans << " " << s1<<endl;
    }
    return 0;
}
