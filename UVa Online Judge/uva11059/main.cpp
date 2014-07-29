#include <iostream>

using namespace std;
int N;
int s[21];
int main()
{
    int test = 1;
    while(cin >> N)
    {
        for(int i = 0 ; i < N;++i)
        {
            cin >> s[i];
        }
        long long int maxI = -5000000000000000000;
        //cout << maxI <<endl;
        if(N == 1)
        {
            if(s[0] < 0)
            {
                s[0] = 0;
            }
            cout << "Case #"<<test<<": The maximum product is "<<s[0]<<"." <<endl;
            test++;
            cout << endl;

        }
        else
        {
            for(int m = 0 ; m < N ;++m)
            {
                for(int i = 0 , j = i + m ; j < N;++i,++j)
                {
                    long long int ans = 1;
                    for(int k = i ; k <= j ;++k)
                    {
                        ans *= s[k];
                    }
                    if(ans > maxI)
                    {
                        maxI = ans;
                    }
                }
            }
            if(maxI < 0)
            {
                maxI = 0;
            }
            cout << "Case #"<<test<<": The maximum product is "<< maxI<<"." <<endl;
            test++;
            cout << endl;
        }
    }
    return 0;
}
