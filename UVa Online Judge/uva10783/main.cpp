#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int count = 1;
    while(T>0){
        int a,b,i,ans=0;
        cin >> a;
        cin >> b;
        for (i = a ; i <= b;i++){
            if(i%2 == 1){
                ans += i;
            }
        }
        cout << "Case "<< count << ": " << ans <<endl;
        count++;
        T--;

    }
    return 0;
}
