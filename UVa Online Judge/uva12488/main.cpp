#include <iostream>
#include <algorithm>
using namespace std;
int N;
int sn[25];
int fn[25];
int main()
{
    while(cin >> N)
    {
        for(int i = 0 ; i < N;++i)
        {
            cin >> sn[i];
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> fn[i];
        }
        int ans = 0;
        for(int k = 0 ; k < N;++k)
        {
            int maxD = 0,nums,index,index2;
            for(int i = k; i < N;++i)
            {
                if(fn[k] == sn[i])
                {
                    index = i;
                    break;
                }
            }
            for(int i = index ; i > k;--i)
            {
                sn[i] = sn[i-1];
                ans++;
            }

        }
        cout << ans <<endl;

    }

    return 0;
}
