#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int st,en;
    int len;
}e[200001];
int prev[200001];
int N;
int nume;

int findx(int x)
{
    if(prev[x] == x)
    {
        return x;
    }
    else
    {
        return prev[x] = findx(prev[x]);
    }
}

void unions(int i, int j )
{
    if(i < j)
    {
        prev[j] = i;
    }
    else
    {
        prev[i] = j;
    }
}

bool cmp(Edge a,Edge b)
{
    return a.len < b.len;
}

int main()
{
    while((cin >> N) && (cin >> nume))
    {
        if(!N && !nume) break;
        for(int i = 0 ;i < N;++i)
        {
            prev[i] = i;
        }
        int sums = 0;
        for(int i = 0 ; i< nume;++i)
        {
            cin >> e[i].st;
            cin >> e[i].en;
            cin >> e[i].len;
            sums += e[i].len;
        }
        sort(e,e+nume,cmp);
        int k = 0;
        int total = 0;
        for(int i = 0 ; i < nume;++i)
        {
            int s1 = findx(e[i].st);
            int s2 = findx(e[i].en);
            if(s1 != s2)
            {
                total+= e[i].len;
                k++;
                unions(s1,s2);
                if(k == N-1)
                {
                    break;
                }
            }
        }
        cout << sums-total<<endl;
    }
    return 0;
}
