#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;


int toDecimal(string s,int base)
{
    int b = 1;
    int sums = 0 ;
    for(int i = s.length()-1;i>= 0 ;--i)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            sums += b*(s[i]-'A' +10);
        }
        else
        {
            sums += b*(s[i]-'0');
        }
        b *= base;

    }
    return sums;
}

string toBase(int num , int base)
{
    string ans ="";
    if(num == 0)
    {
        return "0";
    }
    for(;num;num/=base)
    {
        stringstream ss;
        int n1 = num % base;
        if(n1 >= 10)
        {
            ss << (char) (n1-10 + 'A');
            string s2 ;
            ss >> s2;
            ans += s2;
        }
        else
        {
            ss << (char) (n1 + '0');
            string s2 ;
            ss >> s2;
            ans += s2;
        }
    }
    string temp = ans;
    for(int i = 0 ; i < ans.length();++i)
    {
        temp[i] = ans[ans.length()-1-i];
    }
    return temp;
}

int main()
{
    string s;
    int b1,b2;
    while(cin >> s && cin >> b1 && cin >> b2)
    {
        int num = toDecimal(s,b1);
        string ans = toBase(num,b2);
        if(ans.length() > 7)
        {
            cout << fixed << setw(7) << "ERROR" <<endl;
        }
        else
        {
            cout << fixed << setw(7) << ans <<endl;
        }
    }
    return 0;
}
