#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    int test = 1;
    while(cin >> N && N)
    {

        cout << "Case #" << test++ << ":" <<endl;
        set<int> years[N];
        int y[N];
        int a[N];
        int b[N];
        for(int i = 0 ; i < N;++i)
        {
            cin >> y[i];
            cin >> a[i];
            cin >> b[i];
            int dif1 = y[i]-a[i]+b[i];
            int dif2 = b[i]-a[i];
            int dif2_2 = dif2;
            years[i].insert(y[i]);
            years[i].insert(dif1);
            while(dif1+dif2< 10000)
            {
                //cout << dif1+ dif2 <<endl;
                years[i].insert(dif1+dif2);
                dif2 += dif2_2;
            }
        }
        set<int>::iterator iter1;
        int findans = 0;
        for(iter1 = years[0].begin();iter1!= years[0].end();++iter1)
        {
            int status = 1;
            for(int i = 1 ; i < N;++i)
            {
                if(years[i].find(*iter1) == years[i].end())
                {
                    status = 0;
                    break;
                }
            }
            if(status)
            {
                cout <<"The actual year is " <<*iter1 << ".\n";
                findans = 1;
                break;
            }
        }
        if(findans == 0)
        {
            cout << "Unknown bugs detected." <<endl;
        }
        cout << endl;


    }

    return 0;
}
