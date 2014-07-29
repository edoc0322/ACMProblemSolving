#include <iostream>
#include <algorithm>
#include <string>
#include <map>


using namespace std;

map<string,int> mst;
int N,E;
struct Edge
{
    int p1,p2,len;
} e[19901];
int perv[202];
bool cmp(Edge a,Edge b)
{
    return a.len > b.len;
}

int findx(int x)
{
    if(x == perv[x])return x;
    else return perv[x] = findx(perv[x]);
}

void unions(int i,int j)
{
    if(i < j)
    {
        perv[j] = i;
    }
    else
    {
        perv[i] = j;
    }
}
int main()
{
    int cc = 1;
    while((cin >> N) && (cin >> E))
    {
        if(!N && !E) break;
        mst.clear();
        string s1;
        string s2;
        int len;
        int c = 1;
        for(int i = 1 ; i <= N;++i)
        {
            perv[i] = i;
        }
        for(int i = 0 ; i < E;++i)
        {
            cin >> s1;
            cin >> s2;
            if(mst[s1] == 0)
            {
                mst[s1] = c++;
            }
            if(mst[s2] == 0)
            {
                mst[s2] = c++;
            }
            cin>> len;
            e[i].p1 = mst[s1];
            e[i].p2 = mst[s2];
            e[i].len = len;
        }
        cin >> s1;
        cin >> s2;
        int p,q;
        p = mst[s1];
        q = mst[s2];
        sort(e,e+E,cmp);
        int tot = 0;
        for(int i = 0 ; i < E;++i)
        {
            int so1,so2;
            so1 = findx(e[i].p1);
            so2 = findx(e[i].p2);
            if(so1 != so2)
            {
                unions(so1,so2);

                if(findx(p) == findx(q))
                {
                    tot = e[i].len;
                    break;
                }
            }
        }
        cout << "Scenario #" <<cc++ <<endl;
        cout << tot<<" tons"<<endl;
        cout << endl;
    }
    return 0;
}
