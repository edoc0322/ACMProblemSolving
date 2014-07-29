#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n)
    {
        multiset<long long int> sets;
        int num;
        int long long ans = 0;
        for(int i = 0 ; i < n;++i)
        {
            cin >> num;
            int t;
            for(int j = 0 ; j < num;++j)
            {
                cin >> t;
                sets.insert(t);
            }
            if(sets.size()> 1)
            {
                multiset<long long int>::iterator minT = sets.begin();
                multiset<long long int>::reverse_iterator  maxT = sets.rbegin();
                ans += *maxT - *minT;
                sets.erase(minT);
                sets.erase(--maxT.base());
            }
        }
        cout << ans<<endl;
    }
    return 0;
}
