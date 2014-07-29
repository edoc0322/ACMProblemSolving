#include <iostream>

using namespace std;
int ans[1000000];
int main()
{
    int cnt = 2;
    ans[1] = 1;
    int count = 2;
    while(1)
    {
        ans[count] = ans[count-1] + count;
        if(ans[count] > 1000000000) break;
        count++;

    }
    //cout << count;
    int t;
    cin >> t;
    int k;
    int c = 1;
    for(int i = 0 ; i < t;++i)
    {
        cin >> k;
        int j;
        if(k <0)
        {
            k = -k;
        }
        for(j = 1 ; j < count;++j)
        {
            if(ans[j]>= k &&  (ans[j]-k )%2 == 0) break;
        }
        if(c > 1)
        {
            cout << endl;
        }
        c++;
        cout << j <<endl;
    }
    return 0;
}
