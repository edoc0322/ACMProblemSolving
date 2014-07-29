#include <iostream>
#include <string>
using namespace std;

int main()
{
    int c = 1;
    string s;
    while(cin >> s)
    {
        if(s == "*") break;
        if(s == "Hajj")
        {
            cout <<"Case "<<c++<<": "<<"Hajj-e-Akbar\n";
        }
        else
        {
            cout <<"Case "<<c++<<": "<<"Hajj-e-Asghar\n";
        }
    }
    return 0;
}
