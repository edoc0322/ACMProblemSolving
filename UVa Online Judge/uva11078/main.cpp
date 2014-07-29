#include <iostream>

using namespace std;
int num[100001];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int maxN = -99999999;
        for(int i = 0 ; i < n;++i)
        {
            cin >> num[i];
        }
        int minN = 99999999;
        minN = num[n-1];
        for(int i = n-2; i >= 0 ;--i)
        {
            if(num[i] - minN > maxN)
            {
                maxN = num[i] - minN;
            }
            minN = (num[i] < minN) ? num[i] : minN;
        }

        cout << maxN <<endl;
    }
    return 0;
}
