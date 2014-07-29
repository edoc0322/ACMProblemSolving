#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        long long int A,B,C;
        cin >> A >> B >> C ;
        long long int maxI = sqrt((double) C);
        int status = 0;
        for(long long int i = -maxI ; i <= maxI;++i)
        {
            for(long long int j = i+1 ; j <= maxI;++j)
            {
                if(i+j > A) break;
                if(i*j > B) break;
                for(long long int k = j+1;k <= maxI;++k)
                {
                    if(i+j+k > A) break;
                    if(i+j+k == A && i*j*k == B && i*i+j*j+k*k == C)
                    {
                        cout << i << " " << j << " " << k << endl;
                        status = 1;
                        break;
                    }
                }
                if(status) break;
            }
            if(status) break;
        }
        if(status == 0)
        {
            cout << "No solution." <<endl;
        }
    }
    return 0;
}
