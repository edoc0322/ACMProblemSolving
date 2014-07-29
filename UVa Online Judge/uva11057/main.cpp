#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

int num[1000005];
int main()
{
    int N;
    while(cin >> N)
    {
        memset(num,0,sizeof(num));
        int temp;
        for(int i = 0 ; i < N;++i)
        {
            cin >> temp;
            num[temp]++;
        }
        int total;
        cin >> total;
        if(total%2 == 0)
        {
            if(num[total/2] == 2)
            {
                cout << "Peter should buy books whose prices are " << total/2 << " and " << total/2 << "."<<endl;
            }
            else
            {
                for(int i = total/2-1;i>= 0;--i)
                {
                    if(num[i]&&num[total-i])
                    {
                        cout << "Peter should buy books whose prices are " << i<< " and " << total-i << "."<<endl;
                        break;
                    }
                }
            }
        }
        else
        {
            for(int i = total/2-1;i>= 0;--i)
            {
                if(num[i]&&num[total-i])
                {
                    cout << "Peter should buy books whose prices are " << i<< " and " << total-i << "."<<endl;
                    break;
                }
            }
        }
        cout <<endl;

    }
    return 0;
}
