#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;



struct edge
{
    int start,ends;
    int len;
};

int p[401];

int finds(int i)
{
    while(i != p[i])
    {
        return p[i] = finds(p[i]);
    }
    return i;
}

int unions(int i , int j)
{
    if(i < j )
    {
        p[j] = i;
    }
    else
    {
        p[i] = j;
    }
}
int N,M;

bool cmp(edge e1, edge e2)
{
    return e1.len < e2.len;
}

int main()
{
    while(cin >> N && cin >> M && N && M)
    {
        map<string, int> sets;
        string s;
        edge edges[M];
        for(int i = 0 ; i < N;++i)
        {
            cin >> s;
            sets[s] = i;
            p[i] = i;
        }
        for(int i = 0 ; i  < M ;++i)
        {
            string s1,s2;
            cin >> s1 >> s2;
            int lens ;
            cin >> lens;
            edges[i].start = sets[s1];
            edges[i].ends = sets[s2];
            edges[i].len = lens;
        }
        string ss;
        cin >> ss;

        sort(edges,edges+M,cmp);
        int buildE = 0;
        int sums = 0;
        for(int i = 0 ; i < M;++i)
        {
            int f1 = finds(edges[i].start);
            int f2 = finds(edges[i].ends);
            if(f1 != f2)
            {
                unions(f1,f2);
                buildE++;
                sums += edges[i].len;
            }
        }
        if(buildE != N-1)
        {
            cout << "Impossible\n";
        }
        else
        {
            cout << sums <<endl;
        }



    }

    return 0;
}
