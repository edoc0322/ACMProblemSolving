#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int G;
    string s;
    while(cin >> G && G)
    {
        cin >> s;
        string temp = s;
        int rei = s.length() / G;
        int index = 0;
        for(index = 0 ; index < s.length(); index += rei)
        {
            for(int j = 0 ; j < rei;++j)
            {
                temp[index+j] = s[index+rei-j-1];
            }
        }
        cout << temp << endl;
    }
    return 0;
}
