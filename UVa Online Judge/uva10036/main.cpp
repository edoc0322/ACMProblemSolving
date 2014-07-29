#include <iostream>

using namespace std;
int dp[101];
int w[10001];
int N,K;
int main()
{
    int t;

    cin >> t;
    while(t--)
    {
        cin >> N >> K;
        for(int i = 0 ; i < N;++i)
        {
            cin >> w[i];
        }
        for(int i = 0 ; i <101;++i)
        {
            dp[i] = 0;
        }

        if(w[0] < 0)
        {
            int temp = -w[0];
            for(int i = 1 ; ;++i)
            {
                if(i*K >= temp)
                {
                    dp[i*K-temp] = 1;
                    break;
                }
            }
        }
        else
        {
            dp[w[0]%K] = 1;
        }
        for (int i = 1; i <N;++i)
        {
            int newDp[K];
            for(int j = 0 ; j < K;++j)
            {
                newDp[j] = 0;
            }
            for(int j = 0 ; j < K;++j)
            {
                if(dp[j] == 1)
                {
                    //cout << "dp j " << j <<endl;

                    if(j+w[i] < 0)
                    {
                        int temp = -(w[i]+j);
                        for(int k = 1 ; ;++k)
                        {
                            if(k*K >=temp)
                            {
                                newDp[(k*K-temp) % K] = 1 ;
                                break;
                            }
                        }
                    }
                    else
                    {
                        newDp[(j+w[i])%K] = 1;
                    }

                    if(j-w[i] < 0)
                    {
                        int temp = w[i]-j;
                        for(int k = 1 ; ;++k)
                        {
                            if(k*K >=temp)
                            {
                                newDp[(k*K-temp) % K] = 1 ;
                                break;
                            }
                        }
                    }
                    else
                    {
                        newDp[(j-w[i])%K] = 1;
                    }
                }

            }
            for(int j = 0 ; j < K;++j)
            {
                dp[j] = newDp[j];
            }
        }
        /*
        for(int i = 0 ; i < K;++i)
        {
            cout << "dp " << dp[i] <<endl;
        }
        */

        if(dp[0] == 1)
        {
            cout << "Divisible" <<endl;
        }
        else
        {
            cout << "Not divisible" <<endl;
        }


    }

    return 0;
}
