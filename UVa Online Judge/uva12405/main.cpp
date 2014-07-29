#include <iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    cin >> test;
    int n;
    for(int t = 1 ; t <= test;++t)
    {
        cin >> n;
        int minI = 0;
        string s;
        cin >> s;
        for(int i = 0 ; i < n;)
        {
            if(s[i] == '.')
            {
                minI++;
                i+=3;
            }
            else
            {
                i++;
            }
        }
        cout << "Case " << t << ": " <<minI <<endl;
    }
    return 0;
}
