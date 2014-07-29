#include <iostream>

long long int num11[20];
using namespace std;
int ans[10001];
int main()
{
    num11[0] = 0,num11[1] = 1;
    for(long long int i = 2 ; i < 20;i++){
        num11[i] = num11[i-1]*10 + 1;
    }
    for(int i = 0;i<= 10000;i++){
        if(i % 2 != 0 && i % 5 != 0){
            for(int j = 1 ; j <20;j++){
                if(num11[j]%i == 0){
                    ans[i] = j;
                    if(i <=100){
                        cout << "i is " << i <<", ans is "<< ans[i]<<endl;
                    }
                    break;
                }
            }
        }
    }
    int n;
    while(cin >> n){
        cout << ans[n]<<endl;
    }
    return 0;
}
