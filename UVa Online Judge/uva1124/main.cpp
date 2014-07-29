#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char temp[10000];
    while(cin.getline(temp,10000))
    {
        cout << temp <<endl;
    }
    return 0;
}
