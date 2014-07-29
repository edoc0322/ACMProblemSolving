#include <iostream>
#include <algorithm>
using namespace std;

int a[1000002];
int main()
{

    int n;
    while(cin >> n)
    {
        for(int i = 0 ; i < n;++i)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        int mid;
        if(n%2)
        {
            mid = n/2;
            cout << a[mid];
            int counts = 0;
            for(int i = 0 ; i < n;++i)
            {
                if(a[mid] == a[i])
                {
                    counts++;
                }
            }
            cout << " " << counts << " 1" <<endl;
        }
        else
        {
            mid = n/2-1;
            int mid2 = n/2;
            cout << a[mid];
            int counts = 0;
            for(int i = 0 ; i < n;++i)
            {
                if(a[mid] == a[i] || a[mid2] == a[i])
                {
                    counts++;
                }
            }
            cout << " " << counts << " " << a[mid2]-a[mid]+1 <<endl;
        }
    }
    return 0;
}
