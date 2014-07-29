#include <iostream>

using namespace std;
double L[7];
double G[7],Y[7],R[7];
int vel[100];
int main()
{
    int counts = 1;
    int n;
    while(cin >> n )
    {
        if(n == -1) break;
        for(int i = 0 ; i < n;++i)
        {
            cin >> L[i] >> G[i] >> Y[i] >> R[i];
        }
        for(int i = 30;i <= 60;++i)
        {
            vel[i] = 0;
        }
        int sums = 0;
        for(double v = 30; v <= 60; v += 1.0)
        {
            int status = 1;
            for(int i = 0 ; i < n;++i)
            {
                double s = L[i]/(v/3600);
                double totals = R[i]+G[i]+Y[i];
                double k;
                for(k = s; k - totals >= 0;k-=totals);
                //cout << "k = " << k <<endl;
                if(k> G[i]+Y[i])
                {
                    /*
                    if(v==60.0)
                    {
                        cout << s << " " << totals<<" " << k <<" " <<i  <<" " << G[i] << " " << Y[i] <<endl;
                    }
                    */
                    status = 0;
                    break;
                }
            }
            if(status)
            {
                sums++;
                vel[(int)v] = 1;
                //cout << v <<endl;
            }
        }
        cout << "Case " << counts++ << ": ";
        if(sums == 0)
        {
            cout << "No acceptable speeds." <<endl;
        }
        else
        {
            int s1 = -1,s2 = -1;
            for(int i = 30;i <= 61;++i)
            {
                if(vel[i] == 1&& s1 == -1)
                {
                    s1 = i;
                }
                else if(vel[i] == 1 && s1 != -1)
                {
                    s2 = i;
                }
                else
                {
                    if(s1 != -1)
                    {
                        if(s1 != s2 && s2 != -1)
                        {
                            cout << s1 << "-" << s2;
                            sums -= (s2-s1+1);
                        }
                        else
                        {
                            cout << s1;
                            sums--;
                        }
                        if(sums > 0)
                        {
                            cout << ", ";
                        }
                        s1 = -1;
                        s2 = -1;
                    }
                }
            }
            cout << endl;
        }


    }
    return 0;
}
