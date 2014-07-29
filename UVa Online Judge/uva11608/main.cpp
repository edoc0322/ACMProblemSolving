#include <iostream>

using namespace std;
int c[12];
int m[12];
int main()
{
    int S;
    int test = 1;
    while(cin >> S && S >= 0)
    {
        for(int i = 0 ; i < 12;++i)
        {
            cin >> c[i];
        }
        for(int i = 0 ; i < 12;++i)
        {
            cin >> m[i];
        }
        cout << "Case " << test++ << ":\n";
        for(int i = 0 ; i < 12;++i)
        {
            if(S >= m[i])
            {
                //cout << S <<endl;
                cout << "No problem! :D\n";
                S -= m[i];
                S += c[i];
            }
            else
            {
                S += c[i];
                cout << "No problem. :(\n";
            }
        }
    }

    return 0;
}
