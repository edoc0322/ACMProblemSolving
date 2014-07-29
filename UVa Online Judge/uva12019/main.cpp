#include <iostream>
#include <string>
using namespace std;
int md[20];
string dd[7] = {"Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main()
{
    md[1] = 0 ;
    md[2] = 31 + md[1];
    md[3] = 28 + md[2];
    md[4] = 31 + md[3];
    md[5] = 30 + md[4];
    md[6] = 31 + md[5];
    md[7] = 30 + md[6];
    md[8] = 31 + md[7];
    md[9] = 31 + md[8];
    md[10] = 30 + md[9];
    md[11] = 31 + md[10];
    md[12] = 30 + md[11];
    //int m1_1 = md[2] + md[3] + md[4] + 4 - 1;
    //cout << m1_1 <<endl;
    int m,d;
    int test;
    cin >> test;
    while(test--)
    {
        cin >> m >> d;

        cout << dd[((md[m]+d+5)% 7) ] <<endl;
    }
    return 0;
}
