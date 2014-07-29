#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;


struct node
{
    int L,M;
};
int N;
bool cmp(node n1,node n2)
{
    if(n1.L != n2.L)
    {
        return n1.L < n2.L;
    }
    else
        return n1.M < n2.M;

}

node symbol[10050];
int dp[10050];
int main()
{
    while(cin >> N && N)
    {
        for(int i = 0 ; i < N;++i)
        {
            cin >> symbol[i].L >> symbol[i].M;
        }
        sort(symbol,symbol+N,cmp);

        for(int i = 0 ; i < N;++i)
        {
            dp[i] = 1;
        }
        for(int i = 0 ; i < N;++i)
        {

            for(int j = i+1 ; j < N;++j)
            {
                if(symbol[i].L <= symbol[j].L && symbol[i].M <= symbol[j].M)
                {
                    if(dp[i] +1 > dp[j])
                    {
                        dp[j] = dp[i]+1;
                    }
                }
            }
        }
        int ans = -10000000;
        for(int i = 0 ; i < N;++i)
        {
            ans = max(ans,dp[i]);
        }
        cout << ans <<endl;

        /*
        vector<node> v;
        v.push_back(symbol[0]);
        for(int i = 1 ; i < N;++i)
        {
            if(cmp(symbol[i]))
            {
                v.push_back(symbol[i]);
            }
            else
            {
                *lower_bound(v.begin(),v.end(),symbol[i],cmp) = symbol[i];
            }
        }
        cout << v.size() <<endl;
        */

        /*
        multiset<int> sets;
        multiset<int>::iterator iter;
        sets.insert(10000000);
        for(int i = 0 ; i < N;++i)
        {
            iter = sets.upper_bound(symbol[i].M);
            if(iter != sets.end())
            {
                sets.erase(iter);
                sets.insert(symbol[i].M);
            }
            else
            {
                sets.insert(symbol[i].M);
            }
        }
        cout << sets.size()<<endl;
        */
    }
    cout << "*" <<endl;
    return 0;
}
