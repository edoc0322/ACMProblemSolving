#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int N;
    int counts = 0;
    cin >> N;
    while(N > 0)
    {
        int siz,bit;
        cin >> siz;
        cin >> bit;

        char s[siz+1];
        string ss;
        ss.resize(siz);
        for(int i = 0 ; i < siz-bit;++i)
        {
            ss[i] = '0';
        }
        for(int i = siz-bit ; i < siz;++i)
        {
            ss[i] = '1';
        }
        if(counts > 0)
        {
            cout << endl;
        }
        set<string> sets;
        set<string>::iterator it;
        sort(ss.begin(),ss.end());
        //cout << s <<endl;

        do
        {
            sets.insert(ss);
        }while(next_permutation(ss.begin(),ss.end()));
        for(it = sets.begin() ; it != sets.end();++it)
        {
            cout << *it << endl;
        }
        counts++;
        N--;
    }
    return 0;
}
