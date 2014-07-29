#include <iostream>

using namespace std;
int maps[1030][1030];
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int N ,M;
        cin >> N >> M;
        int nums = 1 << N;
        for(int j = 1 ; j <= nums;++j)
        {
            maps[1][j] = 1;
        }
        int t;
        for(int i = 0 ; i < M;++i)
        {
            cin >> t;
            maps[1][t] = 0;
        }
        int counts = 1 ;
        int ans = 0;
        for(int i = nums; i > 1 ; i = i >> 1 )
        {
            int col = 1;
            for(int j = 1 ; j <= i; j += 2)
            {
                if( maps[counts][j] & maps[counts][j+1])
                {
                    maps[counts+1][col] = 1;
                }
                else if(maps[counts][j] ^ maps[counts][j+1])
                {
                    maps[counts+1][col] = 1;
                    ans++;
                }
                else
                {
                    maps[counts+1][col] = 0;
                }
                col++;
            }
            counts++;
        }
        cout << ans <<endl;
    }
    return 0;
}
