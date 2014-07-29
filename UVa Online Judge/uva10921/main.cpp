#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    char s[100][1];
    s[(int)('A')][0] = '2';
    s[(int)('B')][0] = '2';
    s[(int)('C')][0] = '2';
    s[(int)('D')][0] = s[(int)('E')][0] = s[(int)('F')][0] = '3';
    s[(int)('G')][0] = s[(int)('H')][0] = s[(int)('I')][0] = '4';
    s[(int)('J')][0] = s[(int)('K')][0] = s[(int)('L')][0] = '5';
    s[(int)('M')][0] = s[(int)('N')][0] = s[(int)('O')][0] = '6';
    s[(int)('P')][0] = s[(int)('Q')][0] = s[(int)('R')][0] = s[(int)'S'][0] = '7';
    s[(int)('T')][0] = s[(int)('U')][0] = s[(int)('V')][0] = '8';
    s[(int)('W')][0] = s[(int)('X')][0] = s[(int)('Y')][0] = s[(int)'Z'][0] = '9';
    string ss;
    while((cin >> ss)){
        for(int i = 0 ; i < ss.length();i++){
            if(isalpha(ss[i])){
                cout << s[(int)(ss[i])][0];
            }
            else{
                cout << ss[i];
            }
        }
        cout << endl;

    }

    return 0;
}
