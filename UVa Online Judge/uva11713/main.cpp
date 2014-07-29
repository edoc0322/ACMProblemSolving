#include <iostream>
#include <string>
using namespace std;

int isV(char c)
{
    return (c == 'a' || c== 'e' || c == 'i' || c == 'o' || c =='u');
}

int main()
{
    string s1,s2;
    int N;
    while(cin >> N)
    {
        for(int i = 0 ; i < N;++i)
        {
            cin >> s1;
            cin >> s2;
            if(s1.length() != s2.length())
            {
                cout << "No\n";
            }
            else
            {
                int status = 1;
                for(int j = 0 ; j < s1.length();++j)
                {
                    if( !isV(s1[j]) && !isV(s2[j]) )
                    {
                        if(s1[j] != s2[j])
                        {
                            status = 0;
                            cout << "No\n";
                            break;
                        }
                    }
                    else if(isV(s1[j]) && isV(s2[j] ) )
                    {
                        continue;
                    }
                    else
                    {
                        status = 0;
                        cout << "No\n";
                        break;
                    }
                }
                if(status)
                {
                    cout << "Yes\n";
                }
            }
        }
    }
    return 0;
}
