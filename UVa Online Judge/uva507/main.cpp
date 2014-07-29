#include <iostream>

using namespace std;

long long int arr[20050];
int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;++t)
    {
        int N;
        cin >> N;
        long long int maxI = 0,curI=0;
        int start = 1,end = 1;
        int maxS = 1,maxE = 1;
        for(int i = 0 ; i < N-1;++i)
        {
            cin >> arr[i];
            curI += arr[i];
            if(curI >= 0)
            {
                end++;
                if(curI > maxI)
                {
                    maxI = curI;
                    maxS = start;
                    maxE = end;
                }
                else if(curI == maxI)
                {
                    if(end - start > maxE-maxS)
                    {
                        maxS = start;
                        maxE = end;
                    }
                }
            }
            else
            {
                curI = 0;
                end++;
                start = end;
            }
        }
        if(maxI > 0)
        {
            cout << "The nicest part of route " << t << " is between stops " << maxS << " and " << maxE <<endl;
        }
        else
        {
            cout << "Route " << t << " has no nice parts"<<endl;
        }
    }
    return 0;
}
