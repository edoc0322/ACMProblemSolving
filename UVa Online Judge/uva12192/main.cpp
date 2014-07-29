#include <iostream>
#include <algorithm>
using namespace std;
int maps[503][503];
int N,M;
int main()
{

    while(cin >> N && cin >> M)
    {
        if(!N && !M) break;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = 0 ; j < M;++j)
            {
                cin >> maps[i][j];
            }
        }
        int q;
        cin >> q;
        int L,U;

        while(q--)
        {
            int ans = 0;
            cin >> L >> U;
            for(int i = 0 ; i < N;++i)
            {
                int index = lower_bound(maps[i],maps[i]+M,L) - maps[i];
                if(index == M) continue;
                int low = 0,high = M;
                int mid;
                while(low <= high)
                {
                    mid = (low+high)/2;
                    if(i+mid < N && index+mid < M && maps[i+mid][index+mid] <= U)
                    {
                        low = mid+1;
                    }
                    else
                    {
                        high = mid-1;
                    }
                }
                ans = max(ans,low);
            }
            cout << ans <<endl;
        }
        cout << "-\n";

    }
    return 0;
}
