#include <iostream>
#include <algorithm>
using namespace std;
int N;

int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test;++t)
    {
        cin >> N;
        int cur = 0;
        int maxI = 0;
        int num;
        for(int i = 0 ; i < N;++i)
        {
            cin >> num;
            if(num-cur > maxI)
            {
                maxI = num-cur;
            }
            cur = num;
        }
        cout << "Case " << t << ": " <<maxI <<endl;
    }
    return 0;
}
