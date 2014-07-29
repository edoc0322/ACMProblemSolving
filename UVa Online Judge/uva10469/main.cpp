#include <iostream>

using namespace std;

int main()
{
    int expo = 1;
    int a,b;

    while((cin >> a) && (cin >> b) ){
        cout << ((a&~b)|(~a&b)) <<endl;
    }
    return 0;
}
