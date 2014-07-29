#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    while(t > 0)
    {
        cin >> s;
        if( (s.length() == 1 && s =="1") || (s.length() == 1 && s =="4") ||(s.length() == 2 && s =="78") )
        {
            cout << "+"<<endl;
        }
        else if(s[s.length()-1] == '5' && s[s.length()-2] == '3')
        {
            cout << "-"<<endl;
        }
        else if(s[s.length()-1] == '4' && s[0] == '9')
        {
            cout <<"*"<<endl;
        }
        else if(s[0] == '1' && s[1] == '9' && s[2] == '0')
        {
            cout <<"?"<<endl;
        }

        t--;
    }
    return 0;
}
