#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int arr[500010];
bool cmp(int a,int b)
{
    return abs(a) < abs(b);
}
int main()
{
    int t;
    cin >> t;
    for(int T = 0 ; T < t;++T)
    {
        int N;
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> arr[i];
        }
        sort(arr,arr+N,cmp);
        int status = 0;
        int counts = 0;
        int cur;
        for(int i = 0 ; i < N;++i)
        {
            if(i == 0)
            {
                if(arr[i] < 0)
                {
                    cur = arr[i];
                    status = 1;
                }
                else
                {
                    cur = arr[i];
                    status = 2;
                }
                counts++;
            }
            else
            {
                if(status == 1)
                {
                    if(abs(cur) < abs(arr[i]) && arr[i] > 0)
                    {
                        cur = arr[i];
                        counts++;
                        status = 2;
                    }
                }
                else if(status == 2)
                {
                    if(abs(cur) < abs(arr[i]) && arr[i] < 0)
                    {
                        cur == arr[i];
                        counts++;
                        status = 1;
                    }
                }
            }
        }
        cout << counts <<endl;
    }
    return 0;
}
