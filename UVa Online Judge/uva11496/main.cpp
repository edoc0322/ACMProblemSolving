#include <iostream>

using namespace std;
int N;
int main()
{
    while(cin >> N && N)
    {
        int arr[N];
        int visit[N];
        for(int i = 0 ; i < N;++i)
        {
            cin >> arr[i];
            visit[i] = 0;
        }
        int point = 0;
        int status = 1;
        while(true)
        {
            int np = (point+1)%N;
            if(arr[np]>arr[point])
            {
                for(int j = np;;++j)
                {
                    j = j%N;
                    int k = j-1;
                    if(j == 0)
                    {
                        k = N-1;
                    }
                    if(arr[j]<arr[k])
                    {
                        if(visit[k])
                        {
                            status = 0;
                            break;
                        }
                        visit[k] = 1;
                        point = k;
                        break;
                    }
                }
            }
            else
            {
                for(int j = np;;++j)
                {
                    j = j%N;
                    int k = j-1;
                    if(j == 0)
                    {
                        k = N-1;
                    }
                    if(arr[j]>arr[k])
                    {
                        if(visit[k])
                        {
                            status = 0;
                            break;
                        }
                        visit[k] = 1;
                        point = k;
                        break;
                    }
                }
            }
            if(status == 0)
            {
                break;
            }
        }
        int sums = 0;
        for(int i = 0 ; i < N;++i)
        {
            sums+= visit[i];
        }
        cout << sums <<endl;
    }
    return 0;
}
