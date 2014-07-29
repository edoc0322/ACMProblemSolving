#include <iostream>

using namespace std;

int main()
{

    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        int maxI = -1;
        int minI = 999999999;
        int temp;
        for(int i = 0 ; i < n;++i )
        {
            cin >> temp;
            if(temp > maxI)
            {
                maxI = temp;
            }
            if(temp < minI)
            {
                minI = temp;
            }

        }
        cout << (maxI-minI)*2<<endl;
    }
    return 0;
}
