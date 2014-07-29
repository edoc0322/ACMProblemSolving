#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string s;
    while(cin >> s && s != "#")
    {
        string ss = s;
        sort(ss.begin(),ss.end());
        int counts = 1;
        do
        {
            //cout << ss << "  " << s <<endl;
            if(ss == s)
            {
                cout << std::setw(10);
                cout << counts <<endl;
                break;
            }
            counts++;
        }while(next_permutation(ss.begin(),ss.end()));
    }
    return 0;
}
