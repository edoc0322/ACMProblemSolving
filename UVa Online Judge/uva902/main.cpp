#include <iostream>
#include <string>
#include <map>
using namespace std;

int F[10000];

void buildF(string p)
{
    F[0] = -1;
    int i ;
    for(int j = 1 ; j < p.length();++j)
    {
        i = F[j-1];
        while( (p[j] != p[i+1]) && (i >= 0)  )
        {
            i = F[i];
        }
        if(p[j] == p[i+1])
        {
            F[j] = i+1;
        }
        else
        {
            F[j] = -1;
        }
    }
}

int KMP(string s, string p)
{
    int i = 0 , j = 0;
    while(i < s.length() && j < p.length())
    {
        if(s[i] == p[j])
        {
            i++;
            j++;
        }
        else if(j == 0)
        {
            i++;
        }
        else
        {
            j = F[j-1] + 1;
        }
    }
    if(j == p.length())
    {
        return i - p.length();
    }
    else
    {
        return -1;
    }
}

int main()
{
    int N;
    string s;
    while(cin >> N && cin >> s)
    {
        int maxI = -1;
        string maxS = "";
        map<string,int> sets;
        for(int i = 0 ; i <= s.length()- N;++i)
        {
            string subS = s.substr(i,N);
            sets[subS]++;
            if(sets[subS] > maxI)
            {
                maxI = sets[subS];
                maxS = subS;
            }
        }
        cout << maxS  <<endl;
    }
    return 0;
}
