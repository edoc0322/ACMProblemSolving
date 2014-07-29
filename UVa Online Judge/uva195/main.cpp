#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp (char a,char b)
{
    if(a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')
    {
        if (a == b) return false;
        else return a < b;
    }
    else if(a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')
    {
        if (a == b) return false;
        else return a < b;
    }
    else if(a >= 'a' && a <= 'z' && b >= 'A' && b <= 'Z')
    {
        if (a-'a' == b-'A') return false;
        else return a-'a' < b-'A';
    }
    else if(a >= 'A' && a <= 'Z' && b >= 'a' && b <= 'z')
    {
        if(a-'A' == b-'a') return true;
        return a-'A' < b-'a';
    }
}
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        string s;
        cin >> s;
        sort(s.begin(),s.end(),cmp);
        do
        {
            cout << s <<endl;
        }while(next_permutation(s.begin(),s.end(),cmp));
    }
    return 0;
}
