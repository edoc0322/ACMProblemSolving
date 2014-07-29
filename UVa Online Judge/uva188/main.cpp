#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#define MAXN 2147483647
using namespace std;

int W[10000];
int C;
string s;
int counts;
int calW(string s1)
{
    int sums = 0;
    int bases = 1;
    for(int i = s1.length()-1 ; i >= 0;--i)
    {
        sums += bases * (s1[i]-'a' + 1);
        bases *= 32;
    }
    return sums;
}

int findAns()
{
    for(int i = 0 ; i < counts;++i)
    {
        for(int j = i+1;j < counts;++j)
        {
            if((C/W[i]) % counts ==(C/W[j]) % counts)
            {
                C = min( (C/W[i] + 1) * W[i] ,(C/W[j] + 1) * W[j]);
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    while(getline(cin,s))
    {
        stringstream ss;
        ss << s;
        counts = 0;
        string temp;
        while(ss >> temp)
        {
            int w = calW(temp);
            W[counts++] = w;
        }
        int ans = 0;
        C = 1;
        sort(W,W+counts);
        while(findAns() != 1);
        cout << s <<endl;
        cout << C <<endl <<endl;;

    }
    return 0;
}
