#include <iostream>
#include <cmath>
using namespace std;
int N;
int C[1001];
int P[1001];
int main()
{

    while(cin >> N && N)
    {
        int ans[N];
        int status = 1;
        for(int i = 0 ; i < N;++i)
        {
            ans[i] = 0;
            cin >> C[i];
            cin >> P[i];
            if(abs(P[i]) > N)
            {
                status = 0;
            }
        }
        for(int i = 0 ; i < N;++i)
        {
            int np = i + P[i];
            if(np >= N ||np< 0)
            {
                status = 0;
                break;
            }
            if(ans[np] == 0)
            {
                ans[np] = C[i];
            }
            else
            {
                status = 0;
                break;
            }
        }

        if(status == 0)
        {
            cout << -1 <<endl;
            continue;
        }
        else
        {
            for(int i = 0 ; i < N;++i)
            {
                if(i == 0)
                {
                    cout << ans[i];
                }
                else
                {
                    cout << " " << ans[i];
                }
            }
            cout <<endl;
        }

    }
    return 0;
}
