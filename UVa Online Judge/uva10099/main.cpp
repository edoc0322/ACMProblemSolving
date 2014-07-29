#include <algorithm>
#include <iostream>
using namespace std;

struct edges
{
    int s,d,val;
};
bool cmp(edges a,edges b)
{
    return a.val > b.val;
}
int N,E;
edges e[10010];

int source[10010];
int finds(int i)
{
    while(source[i] != i)
        return source[i] = finds(source[i]);
    return source[i];
}

void unions(int a,int b)
{
    if(a > b)
    {
        source[a] = b;
    }
    else
    {
        source[b] = a;
    }
}
int main()
{
    int test = 1;
    while(cin >> N && cin >> E && N && E)
    {
        int s,d,v;
        for(int i = 1 ; i <= N;++i)
        {
            source[i] = i;
        }
        for(int i = 1 ; i <= E;++i )
        {
            cin >> s >> d >> v;
            e[i-1].s = s;
            e[i-1].d = d;
            e[i-1].val = v;
        }
        cin >> s >> d >> v;
        int maxT;
        sort(e,e+E,cmp);
        for(int i = 0 ; i < E;++i)
        {
            int p1,p2;
            p1 = finds(e[i].s);
            p2 = finds(e[i].d);
            if(p1 != p2)
            {
                unions(p1,p2);
            }
            p1 = finds(s);
            p2 = finds(d);
            if( p1 == p2)
            {
                maxT = e[i].val;
                break;
            }
        }
        int ans = (v % (maxT-1) == 0) ? (v / (maxT-1)) : (v / (maxT-1) + 1);
        cout << "Scenario #" << test++ <<endl;
        if(s == d)
        {
            ans = 0;
        }
        cout << "Minimum Number of Trips = " << ans <<endl <<endl;

    }
    return 0;
}
