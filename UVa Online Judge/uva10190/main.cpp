#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int a,b;
    while( cin >> a && cin >> b)
    {
        if(a == 0 || b == 0)
        {
            cout << "Boring!\n";
            continue;
        }
        if(a / b == a)
        {
            cout << "Boring!\n";
            continue;
        }
        if(a == 1)
        {
            cout << "Boring!\n";
            continue;
        }
        vector<long long int> ans;
        long long int temp = a;
        int status = 1;
        while(temp != 1)
        {
            if(temp%b)
            {
                status = 0;
                break;
            }
            temp = temp / b;
            ans.push_back(temp);
        }
        if(status == 0)
            cout << "Boring!\n";
        else
        {
            cout << a ;
            for(int i = 0 ; i < ans.size();++i)
            {
                cout << " " << ans[i];
            }
            cout << endl;
        }
    }

    return 0;
}
