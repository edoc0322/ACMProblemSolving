#include <iostream>
#include <map>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cstring>
using namespace std;
map< string, int > m;
char name[32];
int main()
{
    int n;
    scanf("%d",&n);
    char temp;
    int d;
    int totalN;
    getchar();
    getchar();
    while(n > 0){
        m.clear();
        totalN = 0;
        while(gets(name) && *name){
            totalN++;
            ++m[name];
        }
        for(map<string,int>::iterator i = m.begin() ; i != m.end();i++){
            cout << (*i).first << " " << fixed << setprecision(4)<< ((double)(*i).second*100) / totalN << endl ;
        }
        if(n > 1){
            cout << endl;
        }
        n--;
    }
    system("pause");
    return 0;
}
