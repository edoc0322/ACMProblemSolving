#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <sstream>

using namespace std;
int N;

struct pairs
{
    int index;
    string value;
};

bool cmp(pairs a , pairs b)
{
    return a.index < b.index;
}

int main()
{
    cin >> N;
    getchar();
    int c = 0;
    while(N--)
    {
        getchar();
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        stringstream ss1(s1),ss2(s2);
        pairs sets[50000];
        int counts = 0;
        while(ss1 >> sets[counts].index)
        {
            ss2 >> sets[counts].value;
            counts++;
        }
        sort(sets,sets+counts,cmp);

        if(c > 0)
        {
            cout << endl;
        }
        c++;

        for(int i = 0 ; i < counts;++i)
        {
            cout << sets[i].value <<endl;
        }

    }

    return 0;
}
