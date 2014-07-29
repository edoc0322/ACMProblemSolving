#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
double f[101];
double r[101];
double d[10005];
int n,m;
int main()
{
    while(cin >> n && n)
    {
        cin >> m;
        for(int i = 0 ; i < n;++i)
        {
            cin >> f[i];
        }
        for(int i = 0 ; i < m;++i)
        {
            cin >> r[i];
        }
        int counts = 0;
        for(int i = 0 ;i < m;++i)
        {
            for(int j = 0 ; j < n;++j)
            {
                d[counts++] = r[i] / f[j];
            }
        }
        sort(d,d+counts);
        double maxD = -1;
        for(int i = 1 ; i < counts;++i)
        {
            double d1 = d[i]/d[i-1];
            if(d1 > maxD)
            {
                maxD = d1;
            }

        }
        cout << fixed << setprecision(2) << maxD <<endl;
    }


    return 0;
}
