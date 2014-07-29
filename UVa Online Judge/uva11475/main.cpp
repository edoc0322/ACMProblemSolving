#include <iostream>
#include <string>
using namespace std;

string s;
string pat;
int F[100050];
void buildF()
{
    F[0] = -1;
    int i ;
    for(int j = 1 ; j < pat.length();++j)
    {
        i = F[j-1];
        while(pat[j] != pat[i+1] && i >= 0)
        {
            i = F[i];
        }
        if(pat[j] == pat[i+1])
        {
            F[j] = i+1;
        }
        else
        {
            F[j] = -1;
        }
    }
}

int KMP()
{
    int lens = s.length();
    int lenp = lens;
    int i = 0 , j = 0;
    while (i < lenp && j < lenp)
    {
        if(s[i] == pat[j])
        {
            ++i;
            ++j;
        }
        else if(j == 0)
        {
            ++i;
        }
        else
        {
            j = F[j-1] + 1;
        }
    }
    return j;
}

int main()
{
    while(cin >> s)
    {
        pat = s;
        for(int i = 0 ; i < s.length();++i)
        {
            pat[i] = s[s.length()-i-1];
        }
        buildF();
        int index = s.length() - KMP();
        cout << s;
        for(int i = index - 1 ; i >= 0;--i)
        {
            cout << s[i];
        }
        cout <<endl;
    }
    return 0;
}
