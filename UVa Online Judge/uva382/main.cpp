#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout <<"PERFECTION OUTPUT\n";
    while(cin >> n){
        if(n == 0){
            cout << "END OF OUTPUT\n";
            break;
        }
        cout << fixed << setw(5) << n;
        cout << "  ";

        int i , j,sum = 0;
        for(i = 1 ; i < n;i++){
            if(n%i == 0){
                sum +=i;
            }
        }
        if(sum == n)
        {
            cout << "PERFECT\n";
        }
        else if(sum > n){
            cout << "ABUNDANT\n";
        }
        else{
            cout << "DEFICIENT\n";
        }

    }
    return 0;
}
