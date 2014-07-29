#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct node
{
    int w,h,index;


};
int visit[20050];
bool cmp(const node & left, const node & right)
{
    if(left.w == right.w) return left.h < right.h;
    return left.w > right.w;
}
int m;
node dolls[20050];
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cin >> m;
        for(int i = 0 ; i < m;++i)
        {
            cin >> dolls[i].w;
            cin >> dolls[i].h;

        }
        sort(dolls,dolls+m,cmp);
        multiset<int> sets;
        multiset<int>::iterator iter;
        sets.insert(10000000);
        for(int i = 0 ; i < m;++i)
        {
            iter = sets.upper_bound(dolls[i].h);
            if(iter != sets.end())
            {
                //cout << "Its me " << dolls[i].h << "   "<< dolls[i].w <<endl;
                //cout << "I erase " << *iter <<endl;
                sets.erase(iter);
                sets.insert(dolls[i].h);
            }
            else
            {
                //cout << "Its me two " << dolls[i].h << "   "<< dolls[i].w <<endl;
                sets.insert(dolls[i].h);
            }
        }
        cout << sets.size() <<endl;

    }
    return 0;
}
