#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

double fac3[10];
int main()
{
    for(int i = 0,j = 3;i < 10;++i,j*=3)
    {
        fac3[i] = (double)1 / (double)j;
        //cout << fac3[i] <<endl;
    }
    string s;
    while(cin >> s)
    {
        if(s=="END") break;
        double n;
        stringstream ss;
        ss << s;
        ss >> n;
        int yes = 1;
        for(int i = 0 ; i < 10;++i)
        {
            double j;
            for(j = 0.0 ; j <= 2.0;j+=1.0)
            {
                if(j*fac3[i] > n) break;
            }
            if(j == 2)
            {
                cout << "NON-MEMBER" <<endl;
                yes = 0;
                break;
            }
            else
            {
                n -= (j-1.0)*fac3[i];
            }
        }
        if(yes)
        {
            cout << "MEMBER" <<endl;
        }
    }
    return 0;
}
