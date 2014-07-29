#include <iostream>
#include <string>
using namespace std;
int ex2[33];
int main()
{
    int i , j;
    ex2[1] = 2;
    for(i = 2 ; i <= 31;i++){
        ex2[i] = ex2[i-1]*2;
    }
    for(i = 1 ;i<=31;i++){
        ex2[i] -= 1;
    }
    string testnum;
    while(cin >> testnum){
        if(testnum == "0"){
            break;
        }
        int sum = 0;
        for(i = 0 ; i < testnum.length();i++){
            sum += (testnum[i]-'0')*ex2[testnum.length()-i];
        }
        cout << sum << endl;
    }

    return 0;
}
