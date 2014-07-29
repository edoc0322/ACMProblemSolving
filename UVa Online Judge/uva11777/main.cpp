#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int counts = 1;
    while(N--)
    {
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d ;
        int test[3];
        cin >> test[0] >> test[1] >> test[2];
        int sums = a+b+c+d;
        sort(test,test+3);
        int ave = (test[2] + test[1]) / 2;
        sums += ave;
        cout << "Case " << counts++ <<": ";
        if(sums>=90)
        {
            cout << "A\n";
        }
        else if(sums>=80)
        {
            cout << "B\n";
        }
        else if(sums >= 70)
        {
            cout << "C\n";
        }
        else if(sums >= 60)
        {
            cout << "D\n";
        }
        else
        {
            cout << "F\n";
        }
    }

    return 0;
}
