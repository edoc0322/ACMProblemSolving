#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while((cin >>s))
    {
        if(s =="0") break;
        int odd = 0 , even = 0;
        int status = 0;
        for(int i = s.length()-1 ; i >= 0 ;i--){
            if(status){
                even += (int)(s[i] - '0');
                status = 0;
            }
            else{
                odd += (int)(s[i] - '0');
                status = 1;
            }
        }
        if((odd-even)%11){
            cout << s << " is not a multiple of 11.\n";
        }
        else{
            cout << s << " is a multiple of 11.\n";
        }
    }
    return 0;
}
