#include <iostream>
#include <string>
using namespace std;

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    else
    {
        return gcd(b,a%b);
    }
}
int main()
{
    int test;
    cin >> test;
    for(int i = 1 ; i <= test;++i)
    {

        string s1,s2;
        cin >> s1;
        cin >> s2;
        int n1,n2;
        int base = 1;
        n1 = 0;
        n2 = 0;
        for(int j = s1.length()-1;j>=0;--j)
        {
            n1 += base * (s1[j]-'0');
            base*= 2;
        }

        base = 1;
        for(int j = s2.length()-1;j>=0;--j)
        {
            n2 += base * (s2[j]-'0');
            base*= 2;
        }
        cout << "Pair #" << i << ": ";
        if(gcd(n1,n2) != 1)
        {
            cout << "All you need is love!\n";
        }
        else
        {
            cout << "Love is not all you need!\n";
        }

    }
    return 0;
}
