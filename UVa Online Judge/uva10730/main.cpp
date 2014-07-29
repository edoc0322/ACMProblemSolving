#include <iostream>

using namespace std;
int num[10001];
int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0) break;
        char c;
        cin >> c;
        //cout << n <<endl;
        for(int i = 0 ; i < n;++i)
        {
            int temp;
            cin >> temp;
            num[temp] = i;
        }
        int dif = 0;
        for(int i = 0 ; i < n;++i)
        {
            for(int j = 1;j+j+i<n;++j)
            {
                if(num[i] < num[i+j] && num[i+j] < num[i+j+j])
                {
                    dif = 1;
                    break;
                }

            }
            if(dif) break;
        }
        if(!dif) cout <<"yes" <<endl;
        else
            cout << "no" <<endl;
    }
    return 0;
}
