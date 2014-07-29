#include <iostream>

using namespace std;

long long int loc[1000000];

int main()
{
    int test;
    cin >> test;
    loc[0] = 0;
    loc[1] = 1;
    for(int i = 2 ; i <= 100000 ;++i)
    {
        loc[i] = loc[i-1] + i;
    }
    for(int i = 1 ; i <= test;++i)
    {
        int x1,y1,x2,y2;
        cout << "Case "<< i <<": ";
        cin >> x1 >> y1 >> x2 >> y2;
        int s1 = x1+y1;
        int s2 = x2+y2;
        int b1,b2;
        b1 = loc[s1];
        b2 = loc[s2];


        b1 += s1 - y1;
        b2 += s2 - y2;

        cout << b2-b1 <<endl;
    }
    return 0;
}
