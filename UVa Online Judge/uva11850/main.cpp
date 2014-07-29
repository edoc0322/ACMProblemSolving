#include <iostream>
#include <algorithm>
using namespace std;
int N;
int main()
{
    while(cin >> N && N)
    {
        int arr[N];
        for(int i = 0 ; i < N;++i)
        {
            cin >> arr[i];
        }
        sort(arr,arr+N);
        int tank = 0;

        for(int i = 0 ; i < N;++i)
        {
            if(i == 0&& arr[i] == 0)
            {
                tank = 1;
            }
            else if(i == 0 && arr[i] != 0)
            {
                tank = 0;
                break;
            }
            else
            {
                if(arr[i]-arr[i-1]<= 200)
                {
                    tank = 1;
                }
                else
                {
                    tank = 0;
                    break;
                }
            }
        }
        if(tank)
        {
            if((1422 - arr[N-1])*2 > 200)
            {
                tank = 0;
            }
        }
        if(tank) cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
