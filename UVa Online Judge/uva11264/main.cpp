#include <iostream>

using namespace std;

int coin[1005];
int main()
{
    int N ;
    int test;
    cin >> test;
    while(test--)
    {
        cin >> N;
        for(int i = 0 ; i < N;++i)
        {
            cin >> coin[i];
        }
        int counts = 1;
        int sums = 1;
        for(int i = 1 ; i < N-1;++i)
        {
            //cout << i << " cmp " << ((sums + coin[i]) < coin[i+1]) <<endl;
            //cout << sums << "   "<<coin[i] << " i and i+1 " << coin[i+1] <<endl;
            if(sums < coin[i] && ( (sums + coin[i]) < coin[i+1]) )
            {
                //cout << sums <<endl;
                sums += coin[i];
                //cout << "after " << sums <<endl;
                //cout << coin[i] << " i and i+1 " << coin[i+1] <<endl;
                counts++;
            }
        }
        if(sums < coin[N-1])
        {
            counts++;
        }
        cout << counts <<endl;
    }
    return 0;
}
