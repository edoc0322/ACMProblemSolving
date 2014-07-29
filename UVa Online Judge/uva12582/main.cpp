#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<int> nodes[30];
int visit[26];
string s;


int main()
{
    int test;
    cin >> test;
    for(int t=  1 ; t <= test;++t)
    {
        cin >> s;
        for(int i = 0 ; i < 26;++i)
        {
            nodes[i].clear();
        }
        memset(visit,0,sizeof(visit));
        for(int i = 0 ; i < s.length();++i)
        {
            int n = s[i] - 'A';
            if(visit[n] == 1)
            {
                for(int j = i-1 ; j >= 0 ;--j)
                {
                    if(s[i] != s[j] && visit[s[j]-'A'] == 1)
                    {
                        //cout << s[j] << "  " << s[i] <<endl;
                        nodes[n].push_back(s[j]-'A');
                        nodes[s[j]-'A'].push_back(n);
                        break;
                    }
                }
                visit[n]++;
            }
            else
            {
                visit[n]++;
            }
        }
        cout << "Case " << t <<endl;
        for(int i = 0 ; i < 26;++i)
        {
            if(nodes[i].size() > 0)
            {
                cout << (char) (i+'A') << " = " << nodes[i].size() <<endl;
            }
        }
    }
    return 0;
}
