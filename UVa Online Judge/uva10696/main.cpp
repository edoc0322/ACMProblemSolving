#include <iostream>

using namespace std;

int f91(int n);
int main()
{
    int n;
    while(cin >> n){
        if(n==0) break;
        cout << "f91(" << n <<") = "<<f91(n)<<endl;
    }
    return 0;
}

int f91(int n){
    if(n >= 101){
        return n-10;
    }
    return f91(f91(n+11));
}
