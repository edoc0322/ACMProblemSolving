#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[1000001];
int main()
{
    int N;
    int t,index = 0;
    cin >> t;
    for(int T = 0 ; T < t ;++T)
    {
        while(cin >> N)
        {
            if(N!= 0)
            {
                arr[index] = N;
                index++;
            }
            else
            {
                sort(arr,arr+index);
                long long int sums = 0;
                int counts = 1;
                int status = 1;
                for(int i = index-1;i>=0;--i)
                {
                    //cout << arr[i] <<endl;
                    int base = 1;
                    for(int j = 0 ; j < counts;++j)
                    {
                        base *= arr[i];
                    }
                    sums += base * 2;
                    //cout << sums <<endl;
                    counts+= 1.0;
                    if(sums > 5000000)
                    {
                        cout << "Too expensive" << endl;
                        status = 0;
                        break;
                    }
                }
                if(status)
                {
                    cout << sums <<endl;
                }
                index = 0;
                break;
            }
        }
    }

    return 0;
}
