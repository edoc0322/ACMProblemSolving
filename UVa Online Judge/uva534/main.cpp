#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

double lengths(double x1,double y1,double x2, double y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

struct Edge
{
    int p1,p2;
    double len;
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

int N;
int Es;
double px[201];
double py[201];
int main()
{
    int c = 1;
    while(cin >> N)
    {
        if(!N) break;
        for(int i = 0 ;i < N;++i)
        {
            //cout << i << endl;
            parv[i] = i;
            cin >> px[i];
            cin >> py[i];
        }
        Es = 0;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = i+1;j < N;++j)
            {
                e[Es].p1 = i;
                e[Es].p2 = j;
                e[Es].len = lengths(px[i],py[i],px[j],py[j]);
                Es++;
            }
        }
        sort(e,e+Es,cmp);
        int k = 0;
        double total = -1.0;
        for(int i = 0 ; i < Es;++i)
        {
            int s1 = findx(e[i].p1);
            int s2 = findx(e[i].p2);
            if(s1 != s2)
            {
                //if(e[i].p1 == 1 || e[i].p2 == 1)
                 //   cout << e[i].len<<endl;
                //cout << e[i].p1 << " " << e[i].p2 <<" " <<e[i].len <<endl;
                k++;
                unions(s1,s2);
                //cout << e[i].len<<endl;
                if (findx(0) == findx(1))
                {
                    total = e[i].len;
                    break;
                }
                if(k == N-1) break;
            }
        }
        cout << "Scenario #"<<c++ <<endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << total<<endl<<endl;;;
    }
    return 0;
}
