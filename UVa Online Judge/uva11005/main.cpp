#include <iostream>

using namespace std;


int money[36];

int getMoney(int n , int base)
{
    int sums = 0;
    for(;n;n/=base)
    {
        sums += money[n % base];
    }
    return sums;
}

int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;++t )
    {

        if(t > 1)
        {
            cout <<endl;
        }
        cout << "Case " << t << ":" <<endl;
        for(int i = 0 ; i < 36;++i)
        {
            cin >> money[i];
        }

        int n;
        cin >> n;
        for(int i = 0 ; i < n ;++i)
        {
            int cost;
            int minC = 99999999;
            int ans[37];
            cin >> cost;
            for(int j = 2 ; j <= 36;++j)
            {
                ans[j] = getMoney(cost,j);
                if(minC > ans[j])
                {
                    minC = ans[j];
                }
            }
            cout << "Cheapest base(s) for number " << cost << ":";
            for(int j = 2 ; j <= 36;++j)
            {
                if(ans[j] == minC)
                {
                    cout << " " << j;
                }
            }
            cout << endl;


        }
    }
    return 0;
}
