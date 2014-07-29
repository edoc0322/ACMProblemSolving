#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
char s[1000000];
int main()
{
    int count = 1;
    while(cin.getline(s,10000000))
    {
        /*
        index[0] = s[0]-'0';
        for(int i = 1 ; i < strlen(s);++i)
        {
            index[i] = index[i-1] + (s[i]-'0');
        }
        */
        //cout << strlen(s)<<endl;
        int N,I,J;
        cin >> N;
        cout << "Case "<<count<<":\n";
        for(int i = 0 ; i < N;++i)
        {
            int ok = 1;
            cin >> I;
            cin >> J;
            for(int j = min(I,J)+1;j<= max(I,J);++j)
            {
                if(s[j] != s[j-1])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        getchar();

        count++;
    }
    return 0;
}
