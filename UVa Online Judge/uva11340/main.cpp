#include <iostream>
#include <map>
#include <cstring>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    int n;
    char ch;
    int mon;
    char s[10001];
    map<char,int> map1;
    while(testcase > 0){
        map1.clear();
        cin >> n;
        for(int i = 0 ; i <n;++i){
            cin >> ch;
            cin >> mon;
            map1[ch] = mon;
        }
        cin >> n;
        int ans = 0;
        getchar();
        for(int i = 0 ; i < n;++i){
            cin.getline(s,10001);
            for(int j = 0 ; j < strlen(s);++j){
                ans += map1[s[j]];
            }
        }
        cout << fixed << setprecision(2) << (double) ans/ 100 << "$\n";

        testcase--;
    }
    return 0;
}
