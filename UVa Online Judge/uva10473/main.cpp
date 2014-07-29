#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctype.h>
using namespace std;

string toHex(int num)
{
    if(num == 0)
    {
        return "0";
    }
    string s = "";
    for(;num;num/=16)
    {
        int b = num % 16;
        if( b >= 10)
        {
            stringstream ss;
            ss << (char) (b - 10 +'A');
            string s2;
            ss >> s2;
            s += s2;
        }
        else
        {
            stringstream ss;
            ss <<  ((char) (b+'0'));
            string s2;
            ss >> s2;
            s += s2;
        }
    }
    string temp = s;
    for(int i = 0 ; i < s.length();++i)
    {
        temp[i] = s[s.length()-i-1];
    }
    //cout << temp ;
    return temp;
}

int main()
{

    int x = 17;
    string s;
    while(cin >> s)
    {
        if(s.find_first_of("-") != string::npos)
        {
            break;
        }
        if(s.find_first_of("x") != string::npos)
        {
            stringstream ss ;
            ss << hex << s.substr(2);
            int ans;
            ss >> ans;
            cout << dec<<ans <<endl;
        }
        else
        {
            stringstream ss ;
            ss << s;
            int ans;
            ss >> ans;
            string s2 = toHex(ans);
            cout << "0x" << s2 <<endl;
        }
    }
    return 0;
}
