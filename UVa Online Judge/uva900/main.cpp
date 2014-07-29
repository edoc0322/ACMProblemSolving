#include <iostream>

using namespace std;
int fib[51];
int main()
{
    int n;
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3;i<=50;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    while(cin >> n){
        if(n == 0){
            break;
        }
        cout << fib[n] << endl;

    }
    return 0;
}
