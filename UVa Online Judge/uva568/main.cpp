#include <iostream>
#include <iomanip>
using namespace std;
int nonzero[10001];
long long int num[10001];

int main()
{
    int temp1,temp2;
    num[0] = num[1] = 1;
    nonzero[0]=1;
    nonzero[1]=1;
    for(int i = 2; i <= 10000;++i)
    {
        nonzero[i] = (i*num[i-1]);
        //cout << nonzero[i] << endl;
        temp2 = nonzero[i];
        while(1)
        {

            temp1 =  temp2 % 10;
            if(temp1 != 0){
                break;
            }
            temp2 = temp2 /10;
        }
        num[i] = temp2 %100000;
        nonzero[i] = temp1;

    }
    int n;

    while(cin >> n)
    {
        cout << setw(5) << n;
        cout << " -> " << nonzero[n]<<endl;
    }
    return 0;
}
