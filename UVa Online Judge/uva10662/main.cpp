#include <iostream>

using namespace std;

int ta[22][22];
int ra[22][22];
int ha[22][22];
int T,H,R;
int main()
{
    while(cin >> T && cin >> R && cin >> H)
    {
        for(int i = 0 ; i < T;++i)
        {
            for(int j = 0 ; j < R+1 ;++j)
            {
                cin >> ta[i][j];
            }
        }
        for(int i = 0 ; i < R;++i)
        {
            for(int j = 0 ; j < H+1 ;++j)
            {
                cin >> ra[i][j];
            }
        }
        for(int i = 0 ; i < H;++i)
        {
            for(int j = 0 ; j < T+1 ;++j)
            {
                cin >> ha[i][j];
            }
        }

        int minA = 999999999;
        int ans[3];
        for(int i = 0 ; i < T;++i)
        {
            for(int j = 1 ; j < R+1;++j)
            {
                if(ta[i][j] == 0)
                {
                    for(int m = 1 ; m < H+1;++m)
                    {
                        if(ra[j-1][m] == 0)
                        {
                            for(int p = 1;p < T+1;++p)
                            {
                                if(ha[m-1][p] == 0 && p-1 == i)
                                {
                                    if(ta[i][0]+ra[j-1][0]+ha[m-1][0] < minA)
                                    {
                                        minA = ta[i][0]+ra[j-1][0]+ha[m-1][0];
                                        ans[0] = i;
                                        ans[1] = j-1;
                                        ans[2] = m-1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(minA == 999999999)
        {
            cout << "Don't get married!" <<endl;
        }
        else
        {
            cout << ans[0] << " " << ans[1] << " " << ans[2] << ":" << minA <<endl;
        }
    }
    return 0;
}
