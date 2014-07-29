#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    while(N--)
    {
        string s;
        cin >> s;
        if(s =="donate")
        {
            int temp;
            cin >> temp;
            ans+=temp;
        }
        else
        {
            cout << ans<<endl;
        }
    }
    return 0;
}
