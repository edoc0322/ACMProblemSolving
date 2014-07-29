#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <stdio.h>
#include <vector>
using namespace std;
map<string,int> m;
vector<string> v;
int main()
{
    int test;
    cin >> test;
    getchar();
    getchar();
    string s;
    int c= 0;
    while(test--)
    {
        m.clear();
        v.clear();
        while(getline(cin,s)&& *s.c_str())
        {
            //cout << s <<endl;
            v.push_back(s);
            //cout << m[s]<<endl;
        }
        int maxI = 0;
        for(int i = 0 ; i < v.size();++i)
        {
            for(int j = i+1 ; j < v.size();++j)
            {
                m[v[i]+v[j]]++;
                if(m[v[i]+v[j]] > maxI)
                {
                    maxI = m[v[i]+v[j]];
                }
                m[v[j]+v[i]]++;
                if(m[v[j]+v[i]] > maxI)
                {
                    maxI = m[v[j]+v[i]];
                }
            }
        }
        map<string,int>::iterator it;
        if(c > 0)
        {
            cout <<endl;
        }

        for(it = m.begin();it != m.end();++it)
        {
            if(it->second == maxI)
            {

                cout << it->first;
                cout << endl;
                break;
            }
        }

        c++;
    }

    return 0;
}
