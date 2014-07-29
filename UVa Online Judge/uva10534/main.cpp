#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp1[10001];
int dp2[10001];
int w[10001];
int N;
int main()
{
    while(cin >> N)
    {
        for(int i = 0 ; i < N;++i)
        {
            //dp1[i] = dp2[i] = 1;
            cin >> w[i];
        }
        int n;
        vector<int> v1,v2;
        n = w[0];
        v1.push_back(n);
        n = w[N-1];
        v2.push_back(n);
        dp1[0] = dp2[N-1] = 1;
        for(int i = 1 ; i < N;++i)
        {
            n = w[i];
            if(n > v1.back())
            {
                v1.push_back(n);
            }
            else
            {
                *lower_bound(v1.begin(),v1.end(),n) = n;
            }
            dp1[i] = v1.size();

            n = w[N-1-i];

            if(n > v2.back())
            {
                v2.push_back(n);
            }
            else
            {
                *lower_bound(v2.begin(),v2.end(),n) = n;
            }
            dp2[N-i-1] = v2.size();
        }

        int maxI = 0;
        for(int i = 0 ; i < N;++i)
        {
            if(min(dp1[i],dp2[i]) > maxI )
            {
                maxI = min(dp1[i],dp2[i]);
            }
        }
        cout << maxI*2-1 <<endl;
    }


    return 0;
}
