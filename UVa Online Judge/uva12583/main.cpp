#include <iostream>
#include <string>
#define MAX(x,y)  ((x < y)? (y) : (x))
using namespace std;

string name;
int main()
{
    int t;
    cin >> t;
    for(int t2 = 1 ; t2 <= t;++t2)
    {
        cout <<"Case " << t2 << ": ";
        int n,k;
        cin >> n >> k;
        cin >> name;
        int ans = 0;
        for(int i = 0;i < n;++i)
        {
            char c1 = name[i];
            for(int j =  MAX(i-k,0);j < i ;++j)
            {

                if(name[j] == c1)
                {
                    ans++;
                    break;
                }


            }
        }
        cout << ans <<endl;
    }
    return 0;
}
