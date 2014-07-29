#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test > 0){
        int L , n,i;

        cin >> L;
        cin >> n;
        int q[n];
        for (i = 0;i<n;i++){
            cin >> q[i];
        }
        int minT = 0;
        for(i = 0 ; i < n;i++){
            minT = max(minT,min(q[i],L-q[i]));
        }
        int maxT = 0;
        for(i = 0 ; i < n;i++){
            maxT = max(maxT,max(q[i],L-q[i]));
        }
        cout << minT << " "<<maxT<<endl;

        test--;
    }
    return 0;
}
