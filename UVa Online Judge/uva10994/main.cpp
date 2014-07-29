#include <iostream>

using namespace std;
int Ff(int i)
{
    if(i == 0) return 0;
    else if(i%10 > 0) return i%10;
    else return Ff(i/10);
}


int main()
{
    for(int i = 0 ; i <= 100;++i)
    {
        cout << i << " " << Ff(i) <<endl;;
    }
    return 0;
}
