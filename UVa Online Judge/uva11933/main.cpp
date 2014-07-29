#include <iostream>

using namespace std;

int main()
{
    int N;
    while(cin >> N && N)
    {
        int mask = 0x80000000;
        int status = 0;
        int a=0x00000000,b =0x00000000;
        for(int i = 0 ; i< 32;++i)
        {
            //cout << mask << " mask " <<endl;
            if(N & mask)
            {

                //cout << " N& " << (N & mask) <<endl;
                if(status == 0)
                {
                    //cout << "i = " << 32-i << endl;
                    a |= mask;
                    status = 1;
                }
                else
                {
                    //cout << "i = " << 32-i << endl;
                    b |= mask;
                    status = 0;
                }
            }
            mask = mask >> 1;
            mask &= 0x7fffffff;
        }
        if(status == 0)
        {
            cout << b << " " << a <<endl;
        }
        else
        {
            cout << a << " " << b <<endl;
        }

    }
    return 0;
}
