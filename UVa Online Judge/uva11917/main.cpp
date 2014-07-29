#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int T = 1 ; T <= t;++T)
    {
        int N;
        cin >> N;
        string s;
        int h;
        map<string,int> sets;
        for(int i = 0 ; i < N;++i)
        {
            cin >>s >> h;
            sets[s] = h;
        }
        int resH;
        cin >> resH;
        string s2;
        cin >> s2;
        cout << "Case " << T << ": ";
        if(sets.find(s2) == sets.end())
        {
            cout << "Do your own homework!";
        }
        else
        {
            if(sets[s2] <= resH)
            {
                cout << "Yesss";
            }
            else if(sets[s2] <= resH+5)
            {
                cout << "Late";
            }
            else
            {
                cout << "Do your own homework!";
            }
        }
        cout <<endl;
    }
    return 0;
}
