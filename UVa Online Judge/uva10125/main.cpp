#include <iostream>

#include <algorithm>
using namespace std;
int S;
int num[1001];
int main()
{
    while(cin >> S && S)
    {
        for(int i = 0 ; i < S;++i)
        {
            cin >> num[i];
        }

        int ok = 0;
        sort(num,num+S);
        for(int i = S-1 ; i >=0;--i)
        {
            for(int j = 0 ; j < S;++j)
            {
                for(int k = j+1;k<S;++k)
                {
                    for(int m = k+1;m<S;++m)
                    {
                        if(num[i] == num[j]+num[k]+num[m] && i != j && i != k && i != m)
                        {
                            cout << num[i]<<endl;
                            ok = 1;
                            break;
                        }
                    }
                    if(ok)
                    {
                        break;
                    }
                }
                if(ok)
                {
                    break;
                }
            }
            if(ok)
                break;
        }
        if(ok == 0)
        {
            cout << "no solution\n";

        }

    }
    return 0;
}
