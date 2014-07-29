#include <iostream>
using namespace std;

int num[1001][2569];
int c[2569];
int maxI = 2569;
void print(int a[]){
    int i = maxI - 1;
    while(a[i] == 0) i--;
    int ans = 0;
    for(int j = i ; j >=0;j--) ans+=a[j];
    cout << ans << endl;
}

int main()
{
    num[0][0] = 1;
    for(int i = 1 ; i <= 1000;++i){
        for(int j = 0;j < maxI;++j){
            c[j] = 0;
        }
        for(int j = 0 ; j < maxI-1;++j){
            c[j+1] = (i*num[i-1][j]+c[j]) /10;

            num[i][j] = (i*num[i-1][j]+c[j])%10;
        }
    }
    int n;
    while(cin >> n){
        print(num[n]);
    }
    return 0;
}
