#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int t=  0 ; t < test;++t)
    {
        int ans = 0;
        int M,N;
        cin >> M >> N;
        int temp;
        map<int,int> sets;
        for(int i = 0 ; i < M;++i)
        {
            cin >> temp;
            sets[temp]++;
        }
        for(int i = 0 ; i < N;++i)
        {
            cin >> temp;
            sets[temp]--;
        }
        map<int,int>::iterator iter;
        for(iter = sets.begin();iter != sets.end();++iter)
        {
            ans += abs(iter->second);
        }
        cout << ans <<endl;
    }
    return 0;
}
