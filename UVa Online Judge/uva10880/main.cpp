#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    int t,T;
    cin >> T;
    for(t = 1 ; t <= T;++t)
    {
        cout << "Case #" << t << ":";
        set<int> sets;
        int C,R;
        cin >> C >> R;
        if(C == R)
        {
            cout << " " << 0 <<endl;
            continue;
        }
        int re = C-R;
        for(int i = 1 ; i <= (int)sqrt(re);++i)
        {
            if(re % i == 0)
            {
                //cout << i << endl;
                if(i > R)
                {
                    sets.insert(i);
                }
                if( ((re)/i) > R)
                {
                    sets.insert(re/i);
                }

            }
        }
        if(sets.size() == 0)
        {
            cout <<endl;
        }
        else
        {
            set<int>::iterator iter;
            for(iter = sets.begin();iter!= sets.end(); ++iter)
            {
                cout << " " << *iter;
            }
            cout << endl;
        }

    }
    return 0;
}
