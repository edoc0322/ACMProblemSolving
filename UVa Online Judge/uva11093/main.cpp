#include <iostream>

using namespace std;
int n;
int main()
{
    int t;
    cin >> t;
    for(int T = 1; T <= t;++T)
    {
        cout << "Case " << T << ": ";
        cin >> n;
        int P[n];
        int Q[n];
        int dif[n];
        for(int i = 0 ; i < n;++i)
        {
            cin >> P[i];
        }
        for(int j = 0 ; j < n;++j)
        {
            cin >> Q[j];
        }
        int sums = 0;
        for(int i = 0 ; i < n;++i)
        {
            dif[i] = P[i]-Q[i];
            sums += dif[i];
        }
        if(sums < 0)
        {
            cout << "Not possible" <<endl;
            continue;
        }

        int sums2 = 0;
        int status = 0;
        int index = -1;
        for(int i = 0 ; i < n;++i)
        {
            sums2 = 0;
            for(int j = i,k = 0 ; k < n;++k)
            {
                sums2 += dif[j];
                if(sums2 < 0) break;
                j++;
                j = j%n;
            }
            if(sums2 >= 0)
            {
                status = 1;
                index = i;
                break;
            }
        }
        if(status)
        {
            cout << "Possible from station " << index+1 <<endl;
        }
        else
        {
            cout << "Not possible" <<endl;
        }
    }
    return 0;
}
