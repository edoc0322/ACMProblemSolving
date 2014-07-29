#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long int ans[50005][3];
int main()
{
    for(int i = 1 ; i <= 50000;++i)
    {
        ans[i][0] = 60000;
        ans[i][1] = 60000;
        ans[i][2] = 60000;
    }
    long long int sq = sqrt((double)50000);
    for(long long int i = 0 ; i <= sq;++i)
    {
        //cout << i <<endl;
        for(long long int j = 0 ; j <= sq;++j)
        {
            if(i*i+j*j > 50000) break;
            for(long long int k = 0 ; k <= sq;++k)
            {
                long long int N = i*i + j*j+k*k;
                if(N > 50000)break;
                if(N <=50000 && N> 0)
                {
                    int temp[3] = {i,j,k};
                    sort(temp,temp+3);
                    //cout << N << " " <<i << " " << j << " " << k <<endl;
                    if(temp[0] < ans[N][0])
                    {
                        ans[N][0] = temp[0];
                        ans[N][1] = temp[1];
                        ans[N][2] = temp[2];
                    }
                    else if(temp[0] == ans[N][0])
                    {
                        if(temp[1] < ans[N][1])
                        {
                            ans[N][0] = temp[0];
                            ans[N][1] = temp[1];
                            ans[N][2] = temp[2];
                        }
                    }
                    //sort(ans[N],ans[N]+3);
                }

            }
        }
    }
    int test;
    cin >> test;
    while(test--)
    {
        int N;
        cin >> N;
        if(ans[N][0] == 60000)
        {
            cout << "-1" <<endl;
        }
        else
        {
            cout << ans[N][0] << " " << ans[N][1] << " " << ans[N][2] <<endl;
        }

    }
    return 0;
}
