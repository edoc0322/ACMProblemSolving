#include <iostream>
#include <algorithm>
using namespace std;
int k[2000001];
int main()
{
    int n;

    while(cin >> n){
        if(!n) break;
        for(int i = 0 ; i < n ;++i){
            cin >> k[i];
        }
        sort(k,k+n);
        for(int i = 0 ;i < n-1;++i){
            cout << k[i] << " ";
        }
        cout << k[n-1]<<endl;
    }
    return 0;
}
