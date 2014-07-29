#include <iostream>

using namespace std;
int N,M;
int num[1005];


int bisection(int vol)
{
    int cap = 0,cnt = 0;
    for(int i = 0 ; i < N;++i)
    {
        if(num[i] > vol) return 1000001;
        if( cap < num[i])
        {
            cap = vol, cnt++;
        }
        cap -= num[i];
    }
    return cnt;
}
int main()
{
    while(cin >> N && cin >> M)
    {
        for(int i = 0 ; i < N;++i)
        {
            cin >> num[i];
        }

        int low = 0,high = 1000000000 ,mid;
        while(low < high)
        {
            mid = (low+high)/2;
            int needR = bisection(mid);
            if(needR > M)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        cout << low <<endl;
    }
    return 0;
}
