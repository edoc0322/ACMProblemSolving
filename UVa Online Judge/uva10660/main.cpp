#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int N;
        cin >> N;
        long long int minAns = 1e9;
        long long int minArr[5];
        long long int ans[5]={1e9,1e9,1e9,1e9,1e9};
        long long int citys[N][3];
        for(int n2 = 0 ; n2 < N;++n2)
        {
            cin >> citys[n2][0] >> citys[n2][1]  >> citys[n2][2];
        }
        for(long long int i = 0 ; i < (long long)25;++i)
        {
            //cout << i << endl;
            for(long long int j = i+1 ; j < (long long)25;++j)
            {
                for(long long int k = j+1 ; k < (long long)25;++k)
                {
                    for(long long int m = k+1 ; m < (long long)25;++m)
                    {
                        for(long long int n = m+1 ; n < (long long)25;++n)
                        {
                            ans[0] = i;
                            ans[1] = j;
                            ans[2] = k;
                            ans[3] = m;
                            ans[4] = n;
                            long long int sums = 0;
                            for(int n2 = 0 ; n2 < N;++n2)
                            {
                                long long int dis = 1e9;
                                for(int aN = 0 ; aN < 5;++aN)
                                {
                                    int x1 = ans[aN]/5;
                                    int y1 = ans[aN]%5;
                                    long long int pro = ( abs(x1-citys[n2][0]) + abs(y1-citys[n2][1])) * citys[n2][2];
                                    dis = min(dis,pro);
                                    //cout << dis <<endl;
                                }
                                sums += dis;
                            }
                            if(sums < minAns)
                            {
                                //cout << "??\n";
                                minAns = sums;
                                for(int aN = 0 ; aN < 5;++aN)
                                {
                                    //cout << ans[aN] << endl;
                                    minArr[aN] = ans[aN];
                                }
                            }
                        }
                    }
                }
            }
            //cout << "?????=";
        }
        //cout << "?????";
        cout << minArr[0] << " " << minArr[1] << " " << minArr[2] << " " << minArr[3] << " " << minArr[4] <<endl;
    }
    return 0;
}
