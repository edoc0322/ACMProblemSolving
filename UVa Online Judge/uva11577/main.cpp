#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;



int main()
{

    int N;
    cin >> N;
    getchar();
    while(N--)
    {
        string s;
        getline(cin,s);
        map<char,int> sets;
        int minI = 0;
        for(int i = 0 ; i < s.length() ; ++i)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                sets[s[i]-'A' + 'a']++;
                if(sets[s[i]-'A' + 'a'] > minI)
                {
                    minI = sets[s[i]-'A' + 'a'];
                }
            }
            else if(s[i] >= 'a' && s[i] <= 'z')
            {
                sets[s[i]]++;
                if(sets[s[i]] > minI)
                {
                    minI = sets[s[i]];
                }
            }
        }
        for(int i = 'a' ; i <= 'z' ;++i)
        {
            if(sets[(char)i] == minI)
            {
                cout << (char) i;
            }
        }
        cout <<endl;

    }

    return 0;
}
