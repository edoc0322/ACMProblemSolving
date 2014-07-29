#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;


int N;
int main()
{

    while(cin >> N)
    {
        vector<int> hashs[26];
        string pattern[10001];
        string oris;
        cin >> oris;
        for(int i = 0 ; i < oris.length();++i)
        {
            hashs[oris[i]-'a'].push_back(i);
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> pattern[i];
        }
        int ok = 0;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < pattern[i].length();++j)
            {
                if(hashs[pattern[j]-'a'].size() > 0 )
                {

                }
                else
                {
                    ok = 1;
                    break;
                }
            }
            if(ok == 1)
            {
                break;
            }
        }
    }

    return 0;
}
