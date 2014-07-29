#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long int num[n];
        for(int i = 0 ; i < n;++i)
        {
            cin >> num[i];
        }
        long long int sums = 0;
        for(int i = 1;i<n;++i)
        {
            for(int j = 0 ; j < i;++j)
            {
                if(num[j] <=num[i])
                {
                    sums ++;
                }
            }
        }
        cout << sums <<endl;

    }

    return 0;
}
