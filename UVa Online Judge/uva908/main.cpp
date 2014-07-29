#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int p1,p2,len;
} e[1000002];
int parv[1000002];
int findx(int x)
{
    if(x == parv[x] )
        return x;
    else
        return parv[x] = findx(parv[x]);
}

void unions(int i,int j)
{
    if(i < j)
    {
        parv[j] = i;
    }
    else
    {
        parv[i] = j;
    }
}

bool cmp(Edge a,Edge b)
{
    return a.len < b.len;
}
int N ,M, K;

int main()
{
    int c = 0;
    while(cin >> N)
    {
        int sums = 0;
        for(int i = 0 ; i < N-1;++i)
        {
            parv[i] = i;
            int a,b,c;
            cin >> a >> b >> c;
            sums+= c;
        }
        parv[N-1] = N-1;
        if(c > 0)
        {
            cout <<endl;
        }
        cout << sums <<endl;
        cin >> K;
        for(int i = 0 ; i < K;++i)
        {
            cin >> e[i].p1  >> e[i].p2  >> e[i].len;
            e[i].p1 -= 1;
            e[i].p2 -= 1;
        }
        cin >> M;
        for(int i = K;i < K+M;++i)
        {
            cin >> e[i].p1 >> e[i].p2 >> e[i].len;
            e[i].p1 -= 1;
            e[i].p2 -= 1;
        }
        M = M+K;

        sort(e,e+M,cmp);
        int k = 0;
        sums = 0;
        for(int i = 0 ; i < M ;++i)
        {
            int s1 = findx(e[i].p1);
            int s2 = findx(e[i].p2);
            if(s1 != s2)
            {

                k++;
                sums+=e[i].len;
                unions(s1,s2);
                if(k == N-1)
                {
                    break;
                }
            }
        }
        cout << sums <<endl;
        c++;

    }

    return 0;
}
