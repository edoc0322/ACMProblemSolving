#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    string tempS;
    string s;
    string sU[1000],sL[1000];
    int count = 0;
    multiset<string> setS;
    multiset<string>::iterator iter;
    set<string>::iterator iter2;
    set<string> re;
    while(cin >> s && s != "#")
    {
        tempS = s;
        for(int i = 0 ; i < s.length();++i){
            tempS[i] = tolower(tempS[i]);
        }
        sort(tempS.begin(),tempS.end());
        setS.insert(tempS);
        sU[count] = s;
        sL[count] = tempS;
        count++;
    }
    int c2;
    for(int i = 0 ; i < count;++i){
        c2 = 0;
        for(iter = setS.begin();iter!=setS.end();++iter){
            if(*iter == sL[i])
            {
                c2++;
            }
        }
        if(c2 == 1){
            re.insert(sU[i]);
        }
    }
    for(iter2 = re.begin();iter2!=re.end();++iter2){
        cout << *iter2 <<endl;
    }

    return 0;
}
