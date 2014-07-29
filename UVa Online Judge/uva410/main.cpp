#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int arr[100];
int main()
{
    int n,m;
    int counts = 1;
    while(cin >> n && cin >> m)
    {
        double sums = 0;
        for(int i = 0 ; i < m;++i)
        {
            cin >> arr[i];
            sums += (double) arr[i];
        }
        for(int i = m; i < 2*n;++i)
        {
            arr[i] = 0;
        }
        sort(arr,arr+2*n);
        cout << "Set #" << counts++<<endl;
        double ave = sums / (double)n;
        //cout << ave <<endl;
        double imb = 0;
        for(int i = 0 ; i < n;++i)
        {
            cout << " " << i << ":";
            if(arr[i] != 0)
            {
                cout << " " << arr[i];
            }
            if(arr[2*n-i-1] != 0)
            {
                cout << " " << arr[2*n-i-1];
            }
            cout << endl;
            double temp = (double)arr[i]+(double)arr[2*n-i-1];
            //cout << temp <<endl;
            imb += fabs(temp-ave);
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << imb <<endl <<endl;
    }
    return 0;
}
