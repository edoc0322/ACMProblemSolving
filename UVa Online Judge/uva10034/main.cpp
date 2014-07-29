#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;


int N;
int parent[101];
struct Point
{
    double x,y;
};

struct Edge
{
    int e1 , e2;
    double len;
};

bool cmp(Edge ee1, Edge ee2)
{
    return ee1.len < ee2.len;
}
int findx(int x)
{
    if(parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = findx(parent[x]);
    }
}

int unions(int i ,int j)
{
    if(i < j )
    {
        parent[j] = i;
    }
    else
    {
        parent[i] = j;
    }
}


double length(double x1,double y1, double x2, double y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}


int main()
{
    int test;
    cin >> test;
    int cc = 0;
    while(test > 0)
    {
        cin >> N;
        Point p[N];
        for(int i = 0 ; i < N;++i)
        {
            cin >> p[i].x;
            cin >> p[i].y;
            parent[i] = i;
        }
        Edge e[N*(N-1)/2];
        int c= 0;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = i+1;j<N;++j)
            {
                e[c].e1 = i;
                e[c].e2 = j;
                e[c].len = length(p[i].x,p[i].y,p[j].x,p[j].y);
                c++;
            }
        }
        sort(e,e+c,cmp);
        Edge ans[101];
        c = 0;
        for(int i = 0 ; i < N*(N-1)/2;++i)
        {
            int p1 = findx(e[i].e1);
            int p2 = findx(e[i].e2);
            if(p1 != p2)
            {
                ans[c] = e[i];
                unions(p1,p2);
                c++;
                if(c == N-1)
                {
                    break;
                }
            }

        }
        if(cc > 0)
        {
            cout << endl;
        }
        double total = 0;
        for(int i = 0 ; i < c;++i)
        {
            total+= ans[i].len;
        }
        cout << fixed << setprecision(2) << total<<endl;
        cc++;


        test--;
    }
    return 0;
}
