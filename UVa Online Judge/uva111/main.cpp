#include <iostream>

using namespace std;

int N;
int dp[22];
int dp2[22];
int w[22];
int w2[22];
int a[22];
int to[22];
int main()
{

    while(cin >> N)
    {
        int c = 0;
        int num = 0;
        cout << "HI"<<endl;;
        for(int i = 0 ; i < N; ++i)
        {
            int temp;
            cin >> temp;
            w[temp-1] = i;
            cout << w[temp-1] << " ";
        }
        cout << endl;
        cout << endl;
        for(int i = 0 ; i < N; ++i)
        {
            w2[w[i]] = i;
            cout << w2[w[i]] << " ";
        }
        cout <<endl;
        int t[22];
        int t1;
        while(cin >> t[0])
        {
            for(int i = 1; i<N; ++i)
            {
                cin >> t[i];
            }
            for(int i = 0; i<N; ++i)
            {
                w[t[i]-1] = i;
                cout << w[t[i]-1] << " ";
            }
            cout << endl;
            for(int i = 0; i<N; ++i)
            {
                to[i] = w2[w[i]];
                cout << to[i] << " ";
            }
            cout <<endl;

            for(int i = 0 ; i < N; ++i)
            {
                dp[i] = 1;
            }
            /*
            for(int i = 0 ; i < N;++i)
            {
                cout << to[i] << " ";
            }
            cout <<endl;
            */

            for(int i = 0 ; i < N; ++i)
            {

                for(int j = i+1 ; j < N; ++j)
                {
                    if(to[i] < to[j])
                    {
                        if(dp[i]+1> dp[j])
                        {
                            dp[j] = dp[i]+1;
                        }

                    }
                    /*
                    if(to[i] > to[j])
                    {
                        if(dp2[i]+1> dp2[j])
                        {
                            dp2[j] = dp2[i]+1;
                        }

                    }
                    */
                }
            }
            int maxI = 0;
            int maxI2 = 0;
            for(int i = 0 ; i< N; ++i)
            {
                //cout << i << " dp is " <<dp[i] << " " << dp2[i]<<endl;
                if(dp[i] > maxI)
                {
                    maxI = dp[i];
                }
                /*
                if(dp2[i] > maxI2)
                {
                    maxI2 = dp2[i];
                }
                */
            }
            cout << maxI<<endl;
            num  = 0;

        }

    }
    return 0;
}
