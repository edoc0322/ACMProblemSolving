#include <iostream>
#include <cmath>
using namespace std;
#include <algorithm>

int main()
{
    int test,m,i;
    int S[501];
    cin >> test;
    while(test > 0){
        cin >> m;
        for(i = 0 ; i < m ; i++)
        {
            cin >> S[i];
        }
        int sum = 0;
        sort(S,S+m);
        for(i = 0 ; i < m;i++){

            sum += fabs(S[i]-S[m/2]);
        }

        cout << sum<<endl;
        test--;
    }
    return 0;
}
