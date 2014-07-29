#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int N;
    while(cin >> N && N)
    {
        map<string , int> sets;
        string s[5];
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < 5;++j)
            {
                cin >> s[j];
            }
            sort(s,s+5);
            string s2 = s[0] + s[1] + s[2] + s[3] + s[4];
            //cout << s2 <<endl;
            sets[s2]++;
        }
        map<string,int>::iterator iter;
        int maxI = 0;
        for(iter = sets.begin();iter!=sets.end();++iter)
        {
            if(iter->second > maxI)
            {
                maxI = iter->second;
            }
        }
        int ans = 0;
        for(iter = sets.begin();iter!=sets.end();++iter)
        {
            if(maxI == iter->second)
            {
                ans+=maxI;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
