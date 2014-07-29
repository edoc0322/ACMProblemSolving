#include <iostream>
#include <cmath>
using namespace std;
long long int p[500];
int main()
{
    long long int n,i;
    int count = 0;

    while(cin>>n){
        if(n == 0 ) break;
        i = sqrt(n);
        if(i*i ==n){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
    return 0;
}
