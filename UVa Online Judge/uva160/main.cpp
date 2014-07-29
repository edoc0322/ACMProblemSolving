#include <iostream>
#include <iomanip>
using namespace std;
bool prime[102];


void eratosthenes()
{
    for (int i=0; i<102; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for (int i=2; i<102; i++)
        if (prime[i])

            for (int k=(102-1)/i, j=i*k; k>=i; k--, j-=i)
                if (prime[k])
                    prime[j] = false;
}

int main()
{
    eratosthenes();
    int n ;
    int ans[102];
    int count ;
    while(cin>>n)
    {
        if(n == 0 ) break;
        count = 0;
        for(int i = 0 ; i < 102; i++)
        {
            ans[i] = 0;
        }
        for(int i = 2 ; i <= n ; i++)
        {
            int temp = i;
            int k = 2;
            while(temp != 1)
            {
                if(prime[k])
                {
                    if(temp % k == 0)
                    {
                        temp = temp / k;
                        ans[k]++;
                    }
                    else
                    {
                        k++;
                    }
                }
                else
                {
                    k++;
                }
            }
        }
        cout << setw(3) << n << "! =" ;
        count = 1;
        for(int i = 2 ; i <= 100; i++)
        {
            if(ans[i] > 0)
            {
                if(count > 15 && count - 15 == 1)
                {
                    cout << "\n      " ;
                    count = 1;
                }
                cout << setw(3) << ans[i];
                count++;
            }
        }
        cout << endl;
    }
}
