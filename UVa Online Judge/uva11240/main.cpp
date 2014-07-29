#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int N;
        cin >> N;
        int findState = 0; // 0: now > new , 1: now < new

        int now;
        cin >> now;
        int ans = 1;
        int cur;
        for(int i = 0 ; i < N-1;++i)
        {
            cin >> cur;
            if(findState == 0)
            {
                if(now > cur)
                {
                    ans++;
                    now = cur;
                    findState = 1;
                }
                else
                {
                    now = cur;
                }
            }
            else
            {
                if(now < cur)
                {
                    ans++;
                    now = cur;
                    findState = 0;
                }
                else
                {
                    now = cur;
                }
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
