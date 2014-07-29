#include <iostream>

using namespace std;

int fib[41];
int main()
{
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3;i <= 40;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    int test;
    cin >> test;
    int n;
    int re[41];
    while(test--){
        cin >> n;
        int r=0,index=0;
        for (int i = 1 ; i <= 40;i++){
            if(n < fib[i]){
               index = fib[i-1];
               r = i-2;
               break;
            }
            else if(n == fib[i] && i > 1){
                index = fib[i];
                r = i-1;
                break;
            }
        }
        int temp = n;
        for (int i = r ;i>= 1;i--){
            re[i] = temp / fib[i+1];
            temp = temp - re[i] * fib[i+1];
        }


        //cout << "r " << r << endl;
        cout << n << " = ";
        for (int i = r;i >= 1;i--){
            cout << re[i];
        }
        cout << " (fib)" << endl;
    }

    return 0;
}
