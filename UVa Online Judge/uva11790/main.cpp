#include <iostream>

using namespace std;
//int dp1[10001];
//int dp2[10001];

int dpw1[10001];
int dpw2[10001];

int h[10001];
int w[10001];

int N;

int main()
{
    int test;
    cin >> test;
    int count = 1;
    while(test > 0)
    {

        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            //dp1[i] = dp2[i] = 1;
            cin >> h[i];
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> w[i];
            dpw1[i] = dpw2[i] = w[i];
        }

        for(int i = 0 ; i < N;++i)
        {
            for(int j = i+1;j < N;++j)
            {
                if(h[i] < h[j] && dpw1[i]+w[j] > dpw1[j])
                {
                    //dp1[j] = dp1[i]+1;
                    dpw1[j] = dpw1[i]+w[j];
                }

                if(h[i] > h[j] && dpw2[i]+w[j] > dpw2[j])
                {
                    //dp2[j] = dp2[i]+1;
                    dpw2[j] = dpw2[i]+w[j];
                }

            }
        }
        /*
        for(int i = 0 ; i < N;++i)
        {
            cout << dpw1[i] << "  " << dpw2[i] <<endl;
        }*/
        int sum1 = 0;
        int sum2 = 0;

        for(int i = 0 ; i < N;++i)
        {
            if(dpw1[i] > sum1)
            {
                sum1 = dpw1[i];
            }

            if(dpw2[i] > sum2)
            {
                sum2 = dpw2[i];
            }
        }
        if(sum1 >= sum2)
        {
            cout << "Case "<<count <<". Increasing ("<<sum1<<"). Decreasing ("<<sum2<<").\n";
        }
        else
        {
            cout << "Case "<<count <<". Decreasing ("<<sum2<<"). Increasing ("<<sum1<<").\n";
        }

        count++;
        test--;

    }
    return 0;
}
