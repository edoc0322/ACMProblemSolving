#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char ss[100];
    char temp[100];
    while(cin.getline(ss,100)){
        if(!strcmp("#",ss)) break;
        if(next_permutation(ss, ss+strlen(ss)))
        {
            cout << ss << endl;
        }
        else
        {
            cout << "No Successor" << endl;
        }

    }
    return 0;
}
