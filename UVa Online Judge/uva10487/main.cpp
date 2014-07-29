#include <iostream>
#include <cmath>
using namespace std;
int N,M;
int w[1001];
int sums[499501];
int q;
int main()
{
    int test = 1;
    while(cin >> N && N)
    {
        cout << "Case " <<test << ":\n";
        for(int i = 0 ; i < N;++i)
        {
            cin >> w[i];
        }
        int count = 0;
        for(int i = 0 ; i < N;++i)
        {
            for(int j = i+1;j<N;++j)
            {
                sums[count++] = w[i]+w[j];
            }
        }
        cin >> M;
        for(int i = 0 ; i < M;++i)
        {
            cin >> q;
            int minI = 1500000000;
            int index = -1;
            for(int j = 0 ; j <count;++j)
            {
                if(abs(q-sums[j])< minI)
                {
                    minI = abs(q-sums[j]);
                    index = j;
                }
            }
            cout << "Closest sum to "<<q<< " is " << sums[index] <<".\n";
        }
        test++;
    }

    return 0;
}
