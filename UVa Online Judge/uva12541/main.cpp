#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;

struct person
{
    string name;
    int d,m,y;
};

bool cmp(person p1,person p2)
{
    if(p1.y != p2.y)
    {
        return p1.y > p2.y;
    }
    else
    {
        if(p1.m != p2.m)
        {
            return p1.m > p2.m;
        }
        else
        {
            return p1.d > p2.d;
        }
    }
}
int main()
{
    while(cin >> N)
    {
        person sets[N];
        for(int i = 0 ; i< N;++i)
        {
            string s;
            int d,m,y;
            cin >> s >> d >> m >> y;
            sets[i].name = s;
            sets[i].d = d;
            sets[i].m = m;
            sets[i].y = y;
        }
        sort(sets,sets+N,cmp);
        cout << sets[0].name <<endl;
        cout << sets[N-1].name <<endl;
    }
    return 0;
}
