#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int S;
    while(cin >> S)
    {
        int ans = 0;
        while(S != 0)
        {
            ans++;
            if(S % 2 == 1)
            {
                if( ((S - 1)/ 2)%2 == 0 || S == 3 )
                {
                    S--;
                }
                else
                {
                    S++;
                }
            }
            else
            {
                S /= 2;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
