#include <iostream>
using namespace std;

int main()
{
    int test1;


    while(cin >> test1)
    {
        if(test1 == -1) break;
        int D,I;
        int i;
        for(i = 0 ; i < test1 ; ++i)
        {
            cin >> D;
            cin >> I;

            int c,k;
            k = 1;
            c = 1;
            while(c < D)
            {
                if(I % 2)
                {
                    k = k*2;
                    I = (I+1) / 2;
                }
                else
                {
                    k = k*2 + 1;
                    I = I/2;
                }
                c++;
            }

            cout << k <<endl;
        }
    }
    return 0;
}
