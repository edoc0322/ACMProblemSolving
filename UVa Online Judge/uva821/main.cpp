#include <iostream>
#include <sstream>
#include <string>
#define maxD 999999
#include <iomanip>
#include <set>
using namespace std;
int maps[101][101];

int main()
{
    string s;
    int maxI;
    int test = 1;

    while(getline(cin,s))
    {
        set<int> sets;

        if(s == "0 0") break;
        stringstream ss(s);
        int a,b;
        maxI = -1;
        for(int i = 0 ; i < 101;++i)
        {
            for(int j = 0 ; j < 101;++j)
            {
                maps[i][j] = maxD;
            }
        }
        while(ss >> a)
        {
            ss >> b;
            if(a == 0) break;
            maps[a][b] = 1;
            sets.insert(a);
            sets.insert(b);
            if(a > maxI)
            {
                maxI = a;
            }
            if(b > maxI)
            {
                maxI = b;
            }
        }
        for(int i = 0 ; i <= maxI;++i)
        {
            maps[i][i] = 0;
        }
        for(int k = 1 ; k <= maxI;++k)
        {
            for(int i = 1 ; i <= maxI;++i)
            {
                for(int j = 1 ; j <= maxI;++j)
                {
                    if(maps[i][j] > maps[i][k] + maps[k][j])
                    {
                        maps[i][j] = maps[i][k] + maps[k][j];
                    }
                }
            }
        }
        int sums = 0;
        for(int i = 1 ; i <= maxI;++i)
        {
            for(int j = 1 ; j <= maxI;++j)
            {
                if(i != j)
                {
                    if(maps[i][j] != maxD)
                    {
                        sums += maps[i][j];
                    }
                }
            }
        }
        cout << "Case " << test++ <<": average length between pages = " << fixed << setprecision(3) << (double) (sums) / (double) (sets.size() * (sets.size()-1)) <<
         " clicks" <<endl;

    }
    return 0;
}
