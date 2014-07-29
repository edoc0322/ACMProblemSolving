#include <iostream>
#include <vector>
using namespace std;

struct E
{
    int x,y;
};
vector<E> sets[10001];

int main()
{
    for(int k = 1 ; k <= 10000; ++k)
    {
        for(int j = k+1 ; j <= 2*k; ++j)
        {
            if( (k*j) % (j-k) == 0)
            {
                E e;
                e.x = (k*j)/(j-k);
                e.y = j;
                sets[k].push_back(e);
            }
        }
    }
    int k;
    while(cin >> k)
    {
        cout << sets[k].size()<<endl;
        for(int i = 0 ; i < sets[k].size();++i)
        {

            cout << 1 <<"/" << k  << " = " << 1 <<"/"<<  sets[k][i].x <<" + " << 1 << "/" << sets[k][i].y<<endl;
        }
    }

    return 0;
}
