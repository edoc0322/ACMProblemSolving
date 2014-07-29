#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int test = 1 ; test <= t;++test)
    {
        int N;
        cin >> N;
        map<int,int> maps[N];
        for(int i = 0 ;i < N;++i)
        {
            int N2;
            cin >> N2;
            int temp;
            for(int j = 0 ; j < N2 ;++j)
            {
                cin >> temp;
                maps[i][temp] = 1;
            }
        }
        map<int,int>::iterator iter1,iter2;
        int sums = 0;
        int sumsArr[N];
        for(int i = 0 ; i < N;++i)
        {
            sumsArr[i] = 0;
        }
        for(int i = 0 ; i < N;++i)
        {
            map<int,int> copys = maps[i];
            for(int j = 0 ; j < N;++j)
            {
                if(i != j )
                {
                    for(iter1 = maps[j].begin(); iter1 != maps[j].end();++iter1)
                    {
                        //cout << " second " <<iter1->second <<endl;
                        maps[i][iter1->first]--;
                    }
                }
            }
            int sums2 = 0;
            for(iter1 = maps[i].begin();iter1 != maps[i].end();++iter1)
            {
                if(iter1->second > 0)
                {

                    sums2++;
                }
            }
            //cout << sums2 <<endl;
            sums += sums2;
            sumsArr[i] = sums2;
            maps[i] = copys;
        }
        cout << "Case " << test << ":";
        for(int i = 0 ; i < N;++i)
        {
            cout << " " << fixed << setprecision(6)<< (double) (sumsArr[i]) / (double) (sums) * 100.0 << "%" ;
        }
        cout << endl;
    }
    return 0;
}
