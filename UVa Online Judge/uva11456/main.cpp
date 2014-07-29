#include <iostream>
#include <algorithm>

using namespace std;
int dp1[2001];
int dp2[2001];
int w[2001];


int N;
bool cmp(int a,int b)
{
    return a < b;
}
int main()
{
    int test;
    int t;
    int n;

    cin >> test;

    while(test > 0)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            dp1[i] = dp2[i] = 1;
            cin >> w[N-i-1];

        }
        if(N == 0)
        {
            cout << "0\n";
            test--;
            continue;
        }

        for(int i = 0 ; i < N;++i)
        {
            for(int j = i+1 ; j < N;++j)
            {
                if(w[i] < w[j])
                {
                    if(dp1[i]+ 1 > dp1[j])
                    {
                        dp1[j] = dp1[i]+1;
                    }
                }

                if(w[i] > w[j])
                {
                    if(dp2[i]+ 1 > dp2[j])
                    {
                        dp2[j] = dp2[i]+1;
                    }
                }

            }
        }
        int maxI = -1;
        for(int i = 0 ; i < N;++i)
        {
            if(dp1[i] + dp2[i] - 1 > maxI)
            {
                maxI = dp1[i] + dp2[i] - 1;
            }
        }
        cout << maxI <<endl;
        test--;
    }

    return 0;
}
