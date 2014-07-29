#include <iostream>

using namespace std;
long long int cake[210000002];
int main()
{
    cake[0] = 1;
    cake[1] = 2;
    cake[2] = 4;
    cake[3] = 7;
    long long int i ;
    for(i = 4;i<=210000000;i++){
        cake[i] = cake[i-1] + i;
    }
    long long int n;
    while(cin>>n){
        if(n < 0) break;
        cout << cake[n]<<endl;
    }

    return 0;
}
