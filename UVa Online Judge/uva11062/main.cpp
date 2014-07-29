#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> sets;
int main()
{
    string s;
    int connectS = 0;
    string emptyS = "";
    while(getline(cin,s))
    {
        int len = s.length();
        for(int i = 0 ; i < len;++i)
        {
            if( (s[i] >= 'a' && s[i] <= 'z' ) || (s[i] >='A' && s[i] <='Z') || (s[i] == '-'))
            {

                while(i < len && (s[i] >= 'a' && s[i] <= 'z' ) || (s[i] >='A' && s[i] <='Z') || (s[i] == '-' ))
                {
                    if((s[i] >='A' && s[i] <='Z') )
                    {
                        s[i] = s[i] - 'A' + 'a';
                    }
                    if( i == len-1 && s[i] == '-' )
                    {
                        connectS = 1;
                        break;
                    }
                    else if(i == len-1 && s[i] != '-')
                    {
                        emptyS+= s[i++];
                        connectS = 0;
                    }
                    else
                    {
                        emptyS += s[i++];
                    }
                    connectS = 0;
                }
            }
            if(connectS == 0)
            {
                if(emptyS != "")
                {
                    sets.insert(emptyS);
                    //cout << "ans =" <<emptyS <<endl;
                }
                emptyS ="";
            }
        }
    }
    set<string>::iterator iter;
    for(iter = sets.begin() ; iter != sets.end() ;++iter)
    {
        cout << *iter <<endl;
    }
    return 0;
}
