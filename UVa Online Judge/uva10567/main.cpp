#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int num[1000005];
int main()
{
    string s;
    while(cin >> s)
    {
        vector<int> numArr[200];
        int counts = 1;
        for(int i = 0 ; i < s.length();++i)
        {
            numArr[s[i]].push_back(i);
        }
        int q;
        cin >> q;
        while(q--)
        {
            int ok = 0;
            int now = 0;
            string s2;
            cin >> s2;
            int ans1,ans2;
            for(int i = 0 ; i < s2.length();++i)
            {
                if(i == 0)
                {
                    int index = lower_bound(numArr[s2[i]].begin(),numArr[s2[i]].end(),now) - numArr[s2[i]].begin();
                    //cout << s2[i] << " " << index << "  " << now<<endl;
                    if(index == numArr[s2[i]].size()) break;
                    ans1 = numArr[s2[i]][index];
                    now = numArr[s2[i]][index] + 1;
                }
                else if(i == s2.length()-1)
                {
                    int index = lower_bound(numArr[s2[i]].begin(),numArr[s2[i]].end(),now) - numArr[s2[i]].begin();
                    //cout << s2[i] << " " << index << "  " << now<<endl;
                    if(index == numArr[s2[i]].size()) break;
                    ans2 = numArr[s2[i]][index];
                    now = numArr[s2[i]][index] + 1;
                    ok = 1;
                }
                else
                {
                    int index = lower_bound(numArr[s2[i]].begin(),numArr[s2[i]].end(),now) - numArr[s2[i]].begin();
                    //cout << s2[i] << " " << index << "  " << now<<endl;
                    if(index == numArr[s2[i]].size()) break;
                    now = numArr[s2[i]][index] + 1;
                }
            }
            if(ok) cout << "Matched " << ans1 << " " << ans2 <<endl;
            else cout << "Not matched" <<endl;
        }
    }
    return 0;
}
