#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int toDecimal(string s, int base)
{
    int sums = 0;
    int b = 1;
    for(int i = s.length()-1;i >= 0 ;--i)
    {
        if(s[i]>= 'A' && s[i] <= 'Z')
        {
            sums += b * (s[i]-'A'+10);
        }
        else
        {
            sums += b*(s[i]-'0');
        }
        b*=base;
    }
    return sums;
}

string toBi(int num)
{
    if(num == 0)
    {
        return "0000000000000";
    }
    string t1 = "",t2;
    for(;num;num/=2)
    {
        stringstream ss;
        ss << (char) ((num % 2) + '0');
        string t;
        ss >> t;
        t1 += t;
    }
    int len = t1.length();
    for(int i = 0 ; i < 13 - len;++i)
    {
        t1 += "0";
    }

    t2 = t1;
    for(int i = 0 ; i < t1.length();++i)
    {
        t2[i] = t1[t1.length()-i-1];
    }
    return t2;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s1,s2,ope;
        cin >> s1 >> ope >> s2;
        int num1 = toDecimal(s1,16);
        int num2 = toDecimal(s2,16);
        int ans ;
        if(ope == "+")
        {
            ans = num1 + num2;
        }
        else
        {
            ans = num1 - num2;
        }

        string a1 = toBi(num1);
        string a2 = toBi(num2);
        cout << a1 <<" " << ope << " " << a2 << " = " << ans <<endl;
    }
    return 0;
}
