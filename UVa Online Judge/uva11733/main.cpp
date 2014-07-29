#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int M,N,money;
int p[10001];
struct edge
{
    int start,ends,len;
};
int finds(int i)
{
    while (i != p[i])
        return p[i] = finds(p[i]);
    return i;
}

void unions(int i ,int j)
{
    if(i < j)
    {
        p[j] = i;
    }
    else
    {
        p[i] = j;
    }
}

bool cmp(edge e1, edge e2)
{
    return e1.len < e2.len;
}

int main()
{
    int test;
    int cases = 1;
    cin >> test;
    while(test--)
    {
        set<int> sets;
        cin >> M >> N >> money;
        for(int i = 0 ; i < M;++i)
        {
            p[i] = i;
        }

        edge edges[N];

        for(int i = 0 ; i < N;++i)
        {
            cin >> edges[i].start;
            edges[i].start--;
            cin >> edges[i].ends;
            edges[i].ends--;
            cin >> edges[i].len;
        }
        sort(edges,edges+N,cmp);
        int counts = 0;
        int sums = 0;
        int cut = 0;
        for(int i = 0 ; i < N;++i)
        {
            int f1,f2;
            f1 = finds(edges[i].start);
            f2 = finds(edges[i].ends);
            if(f1 != f2)
            {
                unions(f1,f2);
                counts++;
                if(edges[i].len >= money)
                {
                    cut++;
                }
                else
                {
                    sums += edges[i].len;
                }

                //if(counts ==  N-1)
                //    break;
            }
        }
        for(int i = 0 ; i < M;++i)
        {
            sets.insert(p[i]);
        }
        cout << "Case #" << cases++ << ": " << sums + ( sets.size()-cut)*money <<" " << (sets.size()-cut)<<endl;

    }
    return 0;
}
