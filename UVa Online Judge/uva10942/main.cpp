#include <iostream>
#include <stdio.h>
using namespace std;

int num[101];
int main()
{
    cout << "Lumberjacks:" <<endl;
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 0 ; i < 10;++i)
            cin >> num[i];
        int status = 0;
        int i;
        for(i = 1 ; i < 10;++i)
        {
            if(num[i] <= num[i-1])
                break;
        }
        if(i == 10) status = 1;
        if(status)
        {
            cout << "Ordered" <<endl;
            continue;
        }
        for(i = 1 ; i < 10;++i)
        {
            if(num[i] >= num[i-1])
                break;
        }
        if(i == 10) status = 1;
        if(status)
        {
            cout << "Ordered" <<endl;
            continue;
        }

        cout << "Unordered" <<endl;
    }
    return 0;
}
