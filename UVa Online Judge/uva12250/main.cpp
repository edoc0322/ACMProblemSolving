#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int c = 1;
    while(cin >> s)
    {
        if(s == "#") break;
        if(s=="HELLO")
        {
            cout << "Case " << c++ << ": ENGLISH\n";
        }
        else if(s=="HOLA")
        {
            cout << "Case " << c++ << ": SPANISH\n";
        }
        else if(s=="HALLO")
        {
            cout << "Case " << c++ << ": GERMAN\n";
        }
        else if(s=="BONJOUR")
        {
            cout << "Case " << c++ << ": FRENCH\n";
        }
        else if(s=="CIAO")
        {
            cout << "Case " << c++ << ": ITALIAN\n";
        }
        else if(s=="ZDRAVSTVUJTE")
        {
            cout << "Case " << c++ << ": RUSSIAN\n";
        }
        else
        {
           cout << "Case " << c++ << ": UNKNOWN\n";
        }
    }
    return 0;
}
