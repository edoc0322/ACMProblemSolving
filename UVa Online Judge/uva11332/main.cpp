#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string int2str(int &i)
{
    string s;
    stringstream ss(s);
    ss << i;

    return ss.str();
}
int main()
{
    string s;
    while(cin >> s)
    {
        if(s == "0") break;
        int sum;
        while(s.length() > 1)
        {
            sum = 0;
            for(int i = 0 ; i < s.length(); i++)
            {
                sum += (int)(s[i] - '0');
            }
            s = int2str(sum);
        }
        cout << s << endl;
    }
    return 0;
}
