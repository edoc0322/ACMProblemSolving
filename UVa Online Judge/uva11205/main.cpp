#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int maps[105][105];
int P,N;

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> P >> N;

        for(int i = 0 ; i < N;++i)
        {

            for(int j = 0 ; j < P;++j)
            {
                cin >> maps[i][j];
            }
        }
        int finalAns = 1e9;
        int minI = (1 << P);
        //cout << minI <<endl;
        for(int i = 0 ; i < minI;++i)
        {
            //cout << i <<endl;
            map<int,int> hashs;
            int status = 1;
            for(int j = 0 ; j < N;++j)
            {
                //cout << j <<endl;
                int ans = 0;
                int sums = 0;
                for(int k = 0 ; k < P;++k)
                {
                    int bits = maps[j][k] & 1;
                    sums |= bits;
                    if(k != P-1)
                        sums = sums << 1;
                }
                ans = i & sums;
                //cout << i << "  " <<  j << "  " << sums <<" "<< ans << endl;
                if(hashs.find(ans) != hashs.end())
                {
                    status = 0;
                    break;
                }
                else
                {
                    hashs[ans]++;
                }
            }
            if(status)
            {
                int temp = i;
                int sums = 0;
                while(temp != 0)
                {
                    int bits = temp & 1;
                    sums += bits;
                    temp = temp >> 1;
                }
                if(sums < finalAns )
                {
                    finalAns = sums;
                }
            }
        }
        if(finalAns == 1e9)
        {
            cout << "0" <<endl;
        }
        else
            cout << finalAns <<endl;
    }

    return 0;
}
