#include <iostream>
#include <string>
#include <map>


using namespace std;

map<string,string> dic;
int N,L;
int main()
{
    while(cin >> L && cin >> N)
    {
        dic.clear();
        string s1,s2;
        for(int i = 0 ; i < L;++i)
        {
            cin >> s1;
            cin >> s2;
            dic[s1] = s2;
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> s1;
            if(dic[s1] != "")
            {
                cout << dic[s1] <<endl;
            }
            else if(s1[s1.length()-1] == 'y' && (s1[s1.length()-2] != 'a' && s1[s1.length()-2] != 'e' && s1[s1.length()-2] != 'i'
                    && s1[s1.length()-2] != 'o'  && s1[s1.length()-2] != 'u' ))
            {
                cout << s1.substr(0,s1.length()-1) << "ies" <<endl;
            }
            else if(s1[s1.length()-1] == 'o' || s1[s1.length()-1] == 's' || s1[s1.length()-1] == 'h' && s1[s1.length()-2] == 'c'
                    || s1[s1.length()-1] == 'h' && s1[s1.length()-2] == 's' || s1[s1.length()-1] == 'x')
            {
                cout << s1 <<"es" <<endl;
            }
            else
            {
                cout << s1 << "s" <<endl;
            }
        }
    }

    return 0;
}
