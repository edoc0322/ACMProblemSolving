#include <iostream>

using namespace std;
struct die
{
    int u,d,n,s,w,e;
} d;

int main()
{
    int n;
    string c;
    while(cin>>n){
        if(n == 0) break;
        d.u = 1,d.d = 6, d.n = 2,d.s = 5,d.w = 3,d.e = 4;
        for(int i = 0 ; i < n ;++i){
            cin >> c;
            if(c == "north"){
                d.n = d.u;
                d.u = d.s;
                d.s = 7- d.n;
                d.d = 7- d.u;
            }
            else if(c == "south"){
                d.s = d.u;
                d.u = d.n;
                d.n = 7- d.s;
                d.d = 7- d.u;
            }
            else if(c == "east"){
                d.e = d.u;
                d.u = d.w;
                d.w = 7-d.e;
                d.d = 7- d.u;
            }
            else if(c == "west"){
                d.w = d.u;
                d.u = d.e;
                d.e = 7-d.w;
                d.d = 7- d.u;
            }
        }
        cout << d.u << endl;

    }

    return 0;
}
