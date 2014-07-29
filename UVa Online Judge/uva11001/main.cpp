#include <iostream>
#include <cmath>
using namespace std;
double len[60001];
int main()
{
    double V,V0;
    while(cin >> V && cin >> V0)
    {
        if(V == 0 && V0 == 0) break;
        for(int i = 0; i < 60001;++i)
        {

            len[i] = 0;

        }
        double maxD = -999;
        int index = 0;
        int maxN = -1;
        for(double d = 1 ; d <= V; d+= 1.0)
        {
            double V2 = V / d;
            if(V2 <= V0) break;
            double D = 0.3 * sqrt(V2-V0) * d;
            //cout << D <<endl;
            if(D > maxD)
            {
                maxD = D;
                maxN = (int) d;
            }
            len[index] = D;
            index++;
        }
        int reN = 0;
        for(int i = 0 ; i < index ; ++i)
        {
            //cout << len[i] <<endl;
            if( fabs(len[i]-maxD) < 1e-9 ) reN++;
        }
        //cout << reN <<endl;
        if(reN > 1 || maxN == -1)
        {
            cout << 0 <<endl;
        }
        else
        {
            cout << maxN <<endl;
        }

    }
    return 0;
}
