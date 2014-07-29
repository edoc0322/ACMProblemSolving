#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toB3(int num)
{
    if(num == 0)
    {
        return "0";
    }

    string s1 = "",s2;
    for(;num;num/=3)
    {
        int b = num % 3;
        stringstream ss;
        ss << (char) (b +'0');
        string s;
        ss >> s;
        s1 += s;
    }

    s2 = s1;
    for(int i = 0 ; i < s1.length();++i)
    {
        s2[i] = s1[s1.length()-i-1];
    }
    return s2;
}

int main()
{
    int n;
    while(cin >> n && n >= 0)
    {
        cout << toB3(n) <<endl;
    }
    return 0;
}
