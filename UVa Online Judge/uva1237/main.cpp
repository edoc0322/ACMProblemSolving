#include <iostream>
#include <string>
using namespace std;

struct data
{
    string name;
    int low,high;
};
int main()
{
    int test;;
    cin >> test;
    for(int t = 0 ; t < test;++t)
    {
        if(t > 0 ) cout << endl;
        int n;
        cin >> n;
        data datas[n];
        for(int i = 0 ; i < n;++i)
        {
            cin >> datas[i].name;
            cin >> datas[i].low;
            cin >> datas[i].high;
        }
        int q;
        cin >> q;
        for(int i = 0 ; i < q;++i)
        {
            int que;
            cin >> que;
            int sums = 0;
            string ans;
            for(int j = 0 ; j < n;++j)
            {
                if(que >= datas[j].low && que <= datas[j].high )
                {
                    ans = datas[j].name;
                    sums++;
                }
            }
            if(sums > 1 || sums == 0)
            {
                ans ="UNDETERMINED";
            }
            cout << ans <<endl;
        }
    }
    return 0;
}
