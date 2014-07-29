#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test>0){
        int a,b;
        cin >> a;
        cin >> b;
        if(a>b){
            cout << ">"<<endl;
        }
        else if(a<b){
            cout << "<"<<endl;
        }
        else{
            cout << "="<<endl;
        }
        test--;

    }
    return 0;
}
