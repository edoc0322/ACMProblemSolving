#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test >0){
        long long int fn,a,b,c,i;
        cin >> fn;
        long long int sum = 0;
        for(i=0;i<fn;i++){
            cin >> a;
            cin >> b;
            cin >> c;
            sum += a*c;
        }

            cout << sum << endl;


        test--;

    }
    return 0;

}
