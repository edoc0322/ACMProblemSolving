#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int N;
string os[10];
string rs[10];
string s;
int main()
{
    int k;
    while(cin >> N && N)
    {
        getchar();
        for(int i = 0 ; i < N;++i)
        {
            getline(cin,os[i]);
            getline(cin,rs[i]);
        }
        getline(cin,s);
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < s.length();++j)
            {
                if(s[j] == os[i][0])
                {
                    int ok = 1;
                    int first = 0;
                    for(k = j ; k < j+os[i].length();++k)
                    {
                        if(k >= s.length())
                        {
                            ok = 0;
                            break;
                        }
                        if(s[k] != os[i][first])
                        {
                            ok = 0;
                            break;
                        }
                        first++;
                    }
                    if(ok)
                    {
                        s.replace(j,os[i].length(),rs[i]);
                        j = 0;
                    }
                    //cout << s <<endl;
                }
            }
        }
        cout << s<<endl;
    }

    return 0;
}
