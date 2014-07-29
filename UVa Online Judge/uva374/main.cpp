#include <iostream>

using namespace std;

int div(long long int b,long long int p,long long int m)
{
    if(p == 0)
    {
        return 1;
    }
    if(p == 1)
    {
        return b % m;
    }
    if(p % 2 == 1)
    {
        return (div(b,p/2,m) * div(b,p/2+1,m)) % m ;
    }
    else
    {
        return (div(b,p/2,m) * div(b,p/2,m)) % m ;
    }

}

int main()
{
    long long int b,p,m;
    while(cin >> b && cin >> p && cin >> m)
    {


        cout << div(b,p,m) <<endl;
    }
    return 0;
}
