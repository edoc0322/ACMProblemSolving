#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i = 1 ; i <= N;++i)
    {
        int L,W,H;
        cin>> L >> W >>H;
        int a,b,c;
        a = 20 >= L;
        b = 20 >= W;
        c = 20 >= H;
        if(a && b && c)
        {
            cout << "Case "<< i <<": good\n";
        }
        else
        {
            cout <<"Case "<< i <<": bad\n";
        }
    }
    return 0;
}
