#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int N,test;
    cin >> N;
    cin >> test;
    map<string,int> m;
    for(int i = 0 ; i < N;++i)
    {
        string s;
        int point;
        cin >> s;
        cin >> point;
        m[s] = point;
    }
    string st;
    int total = 0;
    while(cin >> st)
    {
        if(st == ".")
        {
            cout << total <<endl;
            total = 0;
            test--;
            if(test > 0)
                continue;
            else
                break;
        }
        else
        {
            total += m[st];
        }
    }

    return 0;
}
