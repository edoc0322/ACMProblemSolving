#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int N;
        cin >> N;
        int minN = 1e9;
        if(N == 0)
        {
            cout << 0 <<endl;
            continue;
        }
        for(int h = 1 ; h <= N ;++h)
        {
            if( N % h == 0)
            {
                int wt = N / h;
                for(int w = 1 ; w <= wt;++w)
                {
                    if(wt % w == 0)
                    {
                        int t = wt / w;
                        if(h*w*t == N)
                        {
                            //cout << w << " " << h << " " << t << " "  <<endl;
                            int sums = w*h*2 + w * t* 2 + h*t*2;
                            if(sums < minN)
                            {
                                minN = sums;
                            }
                        }

                    }
                }
            }
        }

        cout << minN <<endl;
    }
    return 0;
}
